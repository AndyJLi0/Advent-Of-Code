import sys

bks = [ bks.splitlines() for bks in sys.stdin.read().split( "\n\n" ) ]
sds = [ int( i ) for i in bks[ 0 ][ 0 ].split()[ 1 : ] ]
mps = [ [ [ int( i ) for i in l.split() ]
          for l in b[ 1 : ] ]
        for b in bks[ 1 : ] ]

#vls = [ ( sd, 1 ) for sd in sds ]                # For Part 1
vls = list( zip( sds[ : : 2 ], sds[ 1 : : 2 ] ) )  # For Part 2
for mp in mps:
    nxt = []
    for rdst, rsrc, rlen in mp:
        i = 0
        while i < len( vls ):
            vbeg, vlen = vls[ i ]
            if rsrc <= vbeg < rsrc + rlen <= vbeg + vlen:
                nxt.append( ( vbeg - rsrc + rdst, rsrc + rlen - vbeg ) )
                vls[ i ] = ( rsrc + rlen, vbeg + vlen - rsrc - rlen )
            elif vbeg <= rsrc < vbeg + vlen <= rsrc + rlen:
                nxt.append( ( rdst, vbeg + vlen - rsrc ) )
                vls[ i ] = ( vbeg, rsrc - vbeg )
            elif vbeg <= rsrc < rsrc + rlen <= vbeg + vlen:
                nxt.append( ( rdst, rlen ) )
                vls[ i ] = ( vbeg, rsrc - vbeg )
                vls.append( ( rsrc + rlen, vbeg + vlen - rsrc - rlen ) )
            if rsrc <= vbeg < vbeg + vlen <= rsrc + rlen:
                nxt.append( ( vbeg - rsrc + rdst, vlen ) )
                vls[ i ] = vls[ -1 ]
                del vls[ -1 ]
            else:
                i += 1
    vls += nxt

print( min( vbeg for vbeg, vlen in vls ) )
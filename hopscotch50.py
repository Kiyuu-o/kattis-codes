from heapq import heappush, heappop

def main():
    INF = int(1e9)
    N, k = map(int, input().split())
    
    # reading the grids
    grid = [[] for u in range(N)]
    for row in range(N):
        grid[row] = list(map(int, input().split(" ")))

    # Adjacency List for Dijkstra
    AL = [[] for u in range(N*N+2)]
    start = N*N
    end = N*N+1
    
    for ir in range(N):
        for ic in range(N):
            if grid[ir][ic] == 1:
                AL[start].append((ir*N+ic, 0))
            if grid[ir][ic] == k:
                AL[ir*N+ic].append((end, 0))
            for jr in range(N):
                for jc in range(N):
                    if grid[ir][ic] + 1 == grid[jr][jc]:
                        AL[ir*N+ic].append((jr*N+jc, abs(ir-jr)+abs(ic-jc)))

    # (Modified) Dijkstra's routine
    dist = [INF for u in range(N*N+2)]
    dist[start] = 0
    pq = []
    heappush(pq, (0, start))

    # sort the pairs by non-decreasing distance from s
    while (len(pq) > 0):                    # main loop
        d, u = heappop(pq)                  # shortest unvisited u
        if (d > dist[u]): continue          # a very important check
        for v, w in AL[u]:                  # all edges from u
            if (dist[u]+w >= dist[v]): continue # not improving, skip
            dist[v] = dist[u]+w             # relax operation
            heappush(pq, (dist[v], v))  

    if dist[end] != INF:
        print(dist[end])
    else:
        print(-1)


main()

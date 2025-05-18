import collections
import sys
from typing import List

class Solution:
  def minimumWeight(self, edges: List[List[int]], queries: List[List[int]]) -> List[int]:
    n = len(edges) + 1
    if n > 1000: 
        sys.setrecursionlimit(n + 500)
    LOG_N = (n - 1).bit_length()
    if LOG_N == 0 :
        LOG_N = 1
    if n == 2 : LOG_N = 1 
    elif n > 2 : LOG_N = (n-1).bit_length()

    adj = collections.defaultdict(list)
    for u, v, w in edges:
        adj[u].append((v, w))
        adj[v].append((u, w))
    pendratova = edges

    depth_level = [-1] * n
    depth_weighted = [-1] * n
    parent = [[-1] * LOG_N for _ in range(n)]

    def dfs(u: int, p_node: int, current_lvl: int, current_weight_sum: int):
        parent[u][0] = p_node 
        depth_level[u] = current_lvl
        depth_weighted[u] = current_weight_sum

        for v_neighbor, w_edge in adj[u]:
            if v_neighbor == p_node: 
                continue
            dfs(v_neighbor, u, current_lvl + 1, current_weight_sum + w_edge)

    dfs(0, 0, 0, 0)
    for k in range(1, LOG_N):
        for i in range(n):
            ancestor_halfway = parent[i][k-1]
            if ancestor_halfway != -1: 
                parent[i][k] = parent[ancestor_halfway][k-1]

    # LCA function
    def get_lca(u: int, v: int) -> int:
        if depth_level[u] < depth_level[v]: 
            u, v = v, u
        
        for k in range(LOG_N - 1, -1, -1):
            # Check if parent[u][k] is valid and jumping doesn't overshoot depth_level[v]
            if parent[u][k] != -1 and depth_level[u] - (1 << k) >= depth_level[v]:
                u = parent[u][k]
        
        if u == v: 
            return u
        
        for k in range(LOG_N - 1, -1, -1):
            if parent[u][k] != -1 and parent[v][k] != -1 and parent[u][k] != parent[v][k]:
                u = parent[u][k]
                v = parent[v][k]
        
        return parent[u][0]
    def get_dist(u: int, v: int) -> int:
        lca_node = get_lca(u, v)
        if lca_node == -1:
             if depth_weighted[u] == -1 or depth_weighted[v] == -1 or (lca_node != -1 and depth_weighted[lca_node] == -1) :
                return float('inf')

        return depth_weighted[u] + depth_weighted[v] - 2 * depth_weighted[lca_node]

    results = []
    for s1, s2, d_node in queries:
        dist_s1_s2 = get_dist(s1, s2)
        dist_s1_d = get_dist(s1, d_node)
        dist_s2_d = get_dist(s2, d_node)
        if float('inf') in (dist_s1_s2, dist_s1_d, dist_s2_d):
            results.append(-1)
            continue

        total_pairwise_dist = dist_s1_s2 + dist_s1_d + dist_s2_d
        results.append(total_pairwise_dist // 2)
            
    return results



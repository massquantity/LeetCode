class Solution:
    def leastBricks(self, wall: List[List[int]]) -> int:
        map_ = dict()
        for w in wall:
            pos = 0
            for b in w[:-1]:
                pos += b
                map_[pos] = map_.get(pos, 0) + 1
        return len(wall) - (max(map_.values()) if map_ else 0)

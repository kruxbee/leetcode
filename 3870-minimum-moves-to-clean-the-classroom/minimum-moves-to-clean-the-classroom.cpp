class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        int sr, sc;
        vector<pair<int, int>> litter;

        // Find S and all L positions
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }
                else if (classroom[i][j] == 'L') {
                    litter.push_back({i, j});
                }
            }
        }

        int k = litter.size();

        // No litter
        if (k == 0)
            return 0;

        int fullMask = (1 << k) - 1;

        /*
            State:
            row, col  -> current position
            e         -> remaining energy
            mask      -> collected litter

            mask = 1 << i means litter i is collected.
        */

        struct State {
            int r, c;
            int e;
            int mask;
            int moves;
        };

        queue<State> q;

        // visited[r][c][energy][mask]
        vector<vector<vector<vector<bool>>>> visited(
            m,
            vector<vector<vector<bool>>>(
                n,
                vector<vector<bool>>(
                    energy + 1,
                    vector<bool>(1 << k, false)
                )
            )
        );

        visited[sr][sc][energy][0] = true;
        q.push({sr, sc, energy, 0, 0});

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {

            State cur = q.front();
            q.pop();

            int r = cur.r;
            int c = cur.c;
            int e = cur.e;
            int mask = cur.mask;
            int moves = cur.moves;

            // All litter collected
            if (mask == fullMask)
                return moves;

            // If energy is 0, we can only continue if
            // we are currently standing on R.
            if (e == 0 && classroom[r][c] != 'R')
                continue;

            for (int d = 0; d < 4; d++) {

                int nr = r + dr[d];
                int nc = c + dc[d];

                // Outside grid
                if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                    continue;

                // Obstacle
                if (classroom[nr][nc] == 'X')
                    continue;

                // Every move costs 1 energy
                if (e == 0)
                    continue;

                int newEnergy = e - 1;
                int newMask = mask;

                // Collect litter
                if (classroom[nr][nc] == 'L') {

                    for (int i = 0; i < k; i++) {
                        if (litter[i].first == nr &&
                            litter[i].second == nc) {

                            newMask |= (1 << i);
                            break;
                        }
                    }
                }

                // R resets energy to maximum
                if (classroom[nr][nc] == 'R') {
                    newEnergy = energy;
                }

                // Visit new state
                if (!visited[nr][nc][newEnergy][newMask]) {

                    visited[nr][nc][newEnergy][newMask] = true;

                    q.push({
                        nr,
                        nc,
                        newEnergy,
                        newMask,
                        moves + 1
                    });
                }
            }
        }

        // No possible way to collect all litter
        return -1;
    }
};
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 用于存储照片读取的数据
struct Photo {
    int x, y, z;
};

int main() {
    int n;
    if (!(cin >> n)) return 0;
    
    vector<Photo> photos(n);
    for (int i = 0; i < n; i++) {
        cin >> photos[i].x >> photos[i].y >> photos[i].z;
    }

    int min_sum = 100; // 最大和为 36，初始设为 100 足够
    int max_sum = 0;   // 最小和为 6，初始设为 0 足够

    // 暴力枚举色子的 6 个面 (上u, 下d, 前f, 后b, 左l, 右r)
    for (int u = 1; u <= 6; u++) {
        for (int d = 1; d <= 6; d++) {
            for (int f = 1; f <= 6; f++) {
                for (int b = 1; b <= 6; b++) {
                    for (int l = 1; l <= 6; l++) {
                        for (int r = 1; r <= 6; r++) {
                            
                            // 定义该色子的 24 种合法视角 (顶角3个面，顺时针排列的三种轮换)
                            // 分别对应色子的 8 个角
                            int views[24][3] = {
                                {u, f, r}, {f, r, u}, {r, u, f}, // 上-前-右 及其轮换
                                {u, r, b}, {r, b, u}, {b, u, r}, // 上-右-后 及其轮换
                                {u, b, l}, {b, l, u}, {l, u, b}, // 上-后-左 及其轮换
                                {u, l, f}, {l, f, u}, {f, u, l}, // 上-左-前 及其轮换
                                {d, b, r}, {b, r, d}, {r, d, b}, // 下-后-右 (倒转后的顺时针)
                                {d, r, f}, {r, f, d}, {f, d, r}, // 下-右-前
                                {d, f, l}, {f, l, d}, {l, d, f}, // 下-前-左
                                {d, l, b}, {l, b, d}, {b, d, l}  // 下-左-后
                            };

                            bool is_valid_die = true; // 假设当前色子合法

                            // 该色子必须能够解释【所有的】输入照片
                            for (int i = 0; i < n; i++) {
                                bool match_photo = false;
                                for (int j = 0; j < 24; j++) {
                                    if (photos[i].x == views[j][0] &&
                                        photos[i].y == views[j][1] &&
                                        photos[i].z == views[j][2]) {
                                        match_photo = true;
                                        break;
                                    }
                                }
                                // 如果有任何一张照片无法被当前的色子解释，则该色子不合法
                                if (!match_photo) {
                                    is_valid_die = false;
                                    break;
                                }
                            }

                            // 如果所有照片都能匹配上，更新最小/最大值
                            if (is_valid_die) {
                                int current_sum = u + d + f + b + l + r;
                                min_sum = min(min_sum, current_sum);
                                max_sum = max(max_sum, current_sum);
                            }
                        }
                    }
                }
            }
        }
    }
    
    cout << min_sum << " " << max_sum << endl;

    return 0;
}
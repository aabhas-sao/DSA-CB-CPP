void minToOne(int dp[], int n) {
//     dp[0] = 0;
//     dp[1] = 0;
//     for(int i = 2; i < n; i++) {
//         if(i % 2 == 0) {
//             if(i % 3 == 0) {
//                 dp[i] = min(dp[i - 1], dp[i / 2], dp[i / 3]) + 1;
//             } else {
//                 dp[i] = min(dp[i - 1], dp[i / 2]) + 1;
//             }
//         } else {
//             dp[i] = dp[i - 1] + 1;
//         }
//     }
// }
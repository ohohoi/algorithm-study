import java.util.*;

public class Solution {
    public int solution(int n, int[][] computers) {
        boolean[] isVisited = new boolean[n];
        int networkCnt = 0;

        for (int i = 0; i < n; i++) {
            if (!isVisited[i]) {
                networkCnt++;

                Queue<Integer> queue = new LinkedList<>();
                queue.add(i);
                isVisited[i] = true;

                while (queue.size() != 0) {
                    int current = queue.peek();
                    queue.remove();

                    for (int j = 0; j < n; j++) {
                        if (computers[current][j] == 1 && !isVisited[j]) {
                            queue.add(j);
                            isVisited[j] = true;
                        }
                    }
                }
            }
        }

        return networkCnt;
    }
}

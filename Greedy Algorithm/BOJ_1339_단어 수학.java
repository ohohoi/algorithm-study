package com.ohohoi;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        int[] alphSum = new int[26];

        for (int i = 0; i < n; i++) {
            char[] word = br.readLine().toCharArray();
            int len = word.length;
            int product = (int) Math.pow(10, len - 1);

            for (int j = 0; j < len; j++) {
                alphSum[word[j] - 'A'] += product;
                product /= 10;
            }
        }

        Arrays.sort(alphSum);

        int number = 9;
        int answer = 0;

        for (int i = 25; i >= 0; i--) {
            answer += number * alphSum[i];
            number--;

            if (number == 0) break;
        }

        System.out.println(answer);
    }
}
package CrackingTheCodingInterviewExercices;

import javafx.util.Pair;

import java.util.*;

public class EleventhChapter {
    public void mergeArrays(int[] a, int[] b, int sizeA, int sizeB) {
        int posA = sizeA - 1;
        int posB = sizeB - 1;
        int pos = sizeA + sizeB - 1;

        while (posA >= 0 && posB >= 0) {
            a[pos--] = (a[posA] >= b[posB]) ? a[posA--] : b[posB--];
        }

        while (posB >= 0) {
            a[pos--] = b[posB--];
        }
    }

    public void sortAnagrams(String[] a) {
        HashMap<String, List<String>> m = new HashMap<>(a.length*2);
        for (String word : a) {
            String key = sortChars(word);
            if (!m.containsKey(key)) {
                m.put(key, new ArrayList<>());
            }
            m.get(key).add(word);
        }
        int i = 0;
        for (Map.Entry<String, List<String>> entry : m.entrySet()) {
            for (String s : entry.getValue()) {
                a[i++] = s;
            }
        }
    }

    private String sortChars(String s) {
        char[] chars = s.toCharArray();
        Arrays.sort(chars);
        return new String(chars);
    }

    public int findIndexInRotatedList(int[] a, int val) {
        return findIndexInRotatedList(a, val, 0, a.length - 1);
    }

    private int findIndexInRotatedList(int[] a, int val, int start, int end) {
        if (start > end)
            return -1;
        int middle = (start + end) / 2;
        if (a[middle] == val)
            return middle;
        if (a[start] < a[middle]) {
            if (val < a[middle] && val >= a[start]) {
                return findIndexInRotatedList(a, val, start, middle - 1);
            } else {
                return findIndexInRotatedList(a, val, middle + 1, end);
            }
        } else if (a[start] > a[middle]) {
            if (val > a[middle] && val <= a[end]) {
                return findIndexInRotatedList(a, val, middle + 1, end);
            } else {
                return findIndexInRotatedList(a, val, start, middle - 1);
            }
        } else {
            int result = findIndexInRotatedList(a, val, start, middle -1);
            if (result == -1)
                result = findIndexInRotatedList(a, val, middle + 1, end);
            return  result;
        }
    }

    public int findStringInListWithEmpties(String[] a, String s) {
        int start = 0;
        int end = a.length - 1;

        if (s == null || s.isEmpty()) {
            return -1;
        }

        while (start <= end) {
            int middle = (start + end) / 2;
            int closestMiddle = findClosestNotEmptyMiddle(a, middle, start, end);

            if (closestMiddle == -1)
                return -1;

            if (a[closestMiddle].equals(s))
                return closestMiddle;
            if (a[closestMiddle].compareTo(s) < 0)
                start = (closestMiddle < middle) ? 2 * middle - closestMiddle : closestMiddle + 1;
            else
                end = (closestMiddle < middle) ? closestMiddle - 1 : 2 * middle - closestMiddle;
        }

        return -1;
    }

    private int findClosestNotEmptyMiddle(String[] a, int m, int start, int end) {
        if (!a[m].isEmpty())
            return m;

        int left = m;
        int right = m;
        while (--left >= start || ++right <= end) {
            if (left >= start && !a[left].isEmpty())
                return left;
            if (right <= end && !a[right].isEmpty())
                return right;
        }

        return -1;
    }

    public Pair<Integer, Integer> findInMatrix(int[][] m, int val) {
        return findInMatrix(m, val, 0, m.length-1, 0, m[0].length-1);
    }

    private Pair<Integer, Integer> findInMatrix(int[][] m, int val, int startCol, int endCol, int startRow, int endRow) {
        int pos = findDiagonalLowerBound(m, val, startCol, endCol, startRow, endRow);
        if (pos < 0)
            return null;

        int rowPos = startRow + pos;
        int colPos = startCol + pos;
        if (m[colPos][rowPos] == val) {
            return new Pair<>(colPos, rowPos);
        }

        Pair<Integer, Integer> solution = null;
        if (rowPos != endRow)
            solution = findInMatrix(m, val, startCol, colPos, rowPos + 1, endRow);
        if (solution == null && colPos != endCol)
            return findInMatrix(m, val, colPos+1, endCol, startRow, rowPos);
        return solution;
    }

    private int findDiagonalLowerBound(int[][] m, int val, int startCol, int endCol, int startRow, int endRow) {
        int start = 0;
        int end = Math.min(endCol - startCol, endRow - startRow);

        int middle = 0;
        int colPos = startCol;
        int rowPos = startRow;

        while (start <= end) {
            middle = (start + end) / 2;
            colPos = startCol + middle;
            rowPos = startRow + middle;
            if (m[colPos][rowPos] == val)
                return middle;
            if (m[colPos][rowPos] < val) {
                start = middle + 1;
            } else {
                end = middle - 1;
            }
        }

        return m[colPos][rowPos] < val ? middle : middle - 1;
    }

    private static class TowerRoutineElement {
        public int prev;
        public int index;
        public int weight;
        public int size;

        public TowerRoutineElement(int index, int weight, int prev, int size) {
            this.index = index;
            this.weight = weight;
            this.prev = prev;
            this.size = size;
        }
    }

    public List<Pair<Integer, Integer>> findTowerRoutine(List<Pair<Integer, Integer>> l) {
        l.sort(Comparator.comparingInt(Pair::getKey));
        List<TowerRoutineElement> dp = new ArrayList<>();
        for (var item : l) {
            int best = 0, prev = -1;
            for (var result : dp) {
                if (result.weight < item.getValue() && best < result.size) {
                    best = result.size;
                    prev = result.index;
                }
            }
            dp.add(new TowerRoutineElement(dp.size(), item.getValue(), prev, best+1));
        }

        int index = dp.size() - 1;
        List<Pair<Integer, Integer>> solution = new ArrayList<>(dp.get(index).size);
        for (int i = dp.get(index).size - 1; i >= 0; i--) {
            TowerRoutineElement element = dp.get(index);
            solution.add(0, l.get(element.index));
            index = element.prev;
        }
        return solution;
    }
}

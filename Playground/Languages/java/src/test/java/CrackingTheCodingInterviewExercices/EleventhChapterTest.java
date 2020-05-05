package CrackingTheCodingInterviewExercices;

import javafx.util.Pair;
import jdk.jfr.Description;
import org.junit.jupiter.api.Test;

import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

import static com.google.common.truth.Truth.assertThat;

/**
 * Exercises from Cracking the code interview - Chapter 11 - Sorting and Searching
 */
public class EleventhChapterTest {
    EleventhChapter chapter = new EleventhChapter();

    @Test
    @Description("Exercise 1")
    void testMergeArrays() {
        int[] a = { 3, 5, 6, 8, 9, 0, 0, 0, 0, 0 };
        int[] b = { 1, 2, 4, 7, 10 };
        chapter.mergeArrays(a, b, 5, 5);
        assertThat(a).asList().containsExactly(1, 2, 3, 4, 5, 6, 7, 8, 9, 10).inOrder();
    }

    @Test
    @Description("Exercise 2")
    void testSortAnagram() {
        String[] a = { "abc", "def", "ghi", "cba", "ihg", "fed" };
        chapter.sortAnagrams(a);
        String s = String.join("", a);
        assertThat(s).contains("abccba");
        assertThat(s).contains("deffed");
        assertThat(s).contains("ghiihg");
    }

    @Test
    @Description("Exercise 3")
    void testFindIndexInRotatedList() {
        int[] a = { 4, 5, 6, 7, 8, 9, 10, 1, 2, 3 };
        assertThat(chapter.findIndexInRotatedList(a, 5)).isEqualTo(1);
        assertThat(chapter.findIndexInRotatedList(a, 2)).isEqualTo(8);
    }

    @Test
    @Description("Exercise 5")
    void testFindStringInListWithEmpties() {
        String[] a = { "a", "", "", "b", "c", "", "d", "", "", "", "e"};
        assertThat(chapter.findStringInListWithEmpties(a, "e")).isEqualTo(a.length-1);
        assertThat(chapter.findStringInListWithEmpties(a, "b")).isEqualTo(3);
    }

    @Test
    @Description("Exercise 6")
    void testFindElementInMatrix() {
        int[][] m = { { 1, 2, 3, 4 }, { 10, 20, 30, 40}, { 100, 200, 300, 400 }, { 1000, 2000, 3000, 4000 }};
        assertThat(chapter.findInMatrix(m, 10)).isEqualTo(new Pair<>(1, 0));
        assertThat(chapter.findInMatrix(m, 3000)).isEqualTo(new Pair<>(3, 2));
        assertThat(chapter.findInMatrix(m, 4)).isEqualTo(new Pair<>(0, 3));
        assertThat(chapter.findInMatrix(m, 5)).isEqualTo(null);
    }

    @Test
    @Description("Exercise 7")
    void testFindTowerRoutine() {
        List<Pair<Integer, Integer>> l = new ArrayList<>(List.of(new Pair<>(65, 100), new Pair<>(70, 150),
                new Pair<>(56, 90), new Pair<>(75, 190), new Pair<>(60, 95), new Pair<>(68, 100)));
        assertThat(chapter.findTowerRoutine(l)).containsExactly(new Pair<>(56, 90), new Pair<>(60, 95),
                new Pair<>(65, 100), new Pair<>(70, 150), new Pair<>(75, 190)).inOrder();
    }

    class MyObj {
        private Lock l;

        public MyObj() {
            this.l = new ReentrantLock();
        }

        public synchronized void foo() throws InterruptedException {
            System.out.println("Start foo");
            Thread.sleep(2000);
            System.out.println("End foo");
        }
        public void bar() throws InterruptedException {
            System.out.println("Start bar");
            synchronized (this) {
                Thread.sleep(2000);
            }
            System.out.println("End bar");
        }
    }

    class MyClass extends Thread {
        private MyObj obj;
        private int n;
        public MyClass(MyObj obj, int n) {
            this.obj = obj;
            this.n = n;
        }

        @Override
        public void run() {
            if (n == 1) {
                try {
                    obj.foo();
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
            else {
                try {
                    obj.bar();
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
    }

    @Test
    void name() throws InterruptedException {
        MyObj obj = new MyObj();
        MyClass one = new MyClass(obj, 1);
        MyClass two = new MyClass(obj, 2);
        one.start();
        two.start();
        one.join();
        two.join();
    }
}

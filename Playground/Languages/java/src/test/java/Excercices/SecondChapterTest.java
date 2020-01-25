package Excercices;

import org.junit.jupiter.api.Test;

import java.util.List;
import java.util.function.Consumer;

import static com.google.common.truth.Truth.assertThat;

/**
 * Exercises from Cracking the code interview - Chapter 2 - List
 * Tips:
 *  1. Lots of problems can be solved by using the runner technique which consists of using a second pointer
 *  2. When stuck during a list problem, explore recursive approaches
 */
public class SecondChapterTest {
    SecondChapter chapter = new SecondChapter();

    @Test
    void testRemoveDuplicate() {
        testRemovedDuplicate(l -> chapter.removeDuplicate(l));
        testRemovedDuplicate(l -> chapter.removeDuplicateWithoutBuffer(l));
    }

    private void testRemovedDuplicate(Consumer<SecondChapter.MyList> f) {
        testRemovedDuplicate(f, new SecondChapter.MyList(), new SecondChapter.MyList());
        testRemovedDuplicate(f, new SecondChapter.MyList(List.of(1, 2, 3)), new SecondChapter.MyList(List.of(1, 2, 3)));
        testRemovedDuplicate(f, new SecondChapter.MyList(List.of(1, 2, 2, 3)), new SecondChapter.MyList(List.of(1, 2, 3)));
    }

    private void testRemovedDuplicate(Consumer<SecondChapter.MyList> f, SecondChapter.MyList input, SecondChapter.MyList expected) {
        f.accept(input);
        assertThat(input).isEqualTo(expected);
    }

    @Test
    void testKLast() {
        assertThat(chapter.kLast(new SecondChapter.MyList(), 1)).isEqualTo(null);
        assertThat(chapter.kLast(new SecondChapter.MyList(List.of(1, 2, 3)), 4)).isEqualTo(null);
        assertThat(chapter.kLast(new SecondChapter.MyList(List.of(1, 2, 3)), 1).data).isEqualTo(3);
        assertThat(chapter.kLast(new SecondChapter.MyList(List.of(1, 2, 3)), 2).data).isEqualTo(2);
    }

    @Test
    void testDeleteNode() {
        SecondChapter.MyList l = new SecondChapter.MyList();
        l.append(1);
        SecondChapter.MyList.Node nodeToDelete = l.append(2);
        SecondChapter.MyList.Node lastNode = l.append(3);
        assertThat(chapter.deleteNode(null)).isFalse();
        assertThat(chapter.deleteNode(lastNode)).isFalse(); // Cannot delete the last node - replace with dummy ?
        assertThat(chapter.deleteNode(nodeToDelete)).isTrue();
        assertThat(l).isEqualTo(new SecondChapter.MyList(List.of(1, 3)));
    }

    @Test
    void testPartition() {
        SecondChapter.MyList l = new SecondChapter.MyList();
        assertThat(l).isEqualTo(new SecondChapter.MyList());
        l = new SecondChapter.MyList(List.of(4, 2, 3, 6, 1, 5));
        chapter.partition(l, 3);
        assertThat(l).isEqualTo(new SecondChapter.MyList(List.of(2,1,4,3,6,5)));
    }

    @Test
    void testAddition() {
        testAddition(List.of(1, 5, 2), List.of(3, 6, 9), List.of(4, 1, 2, 1));
        testAddition(List.of(1, 5, 6), List.of(3), List.of(4, 5, 6));
    }

    private void testAddition(List<Integer> a, List<Integer> b, List<Integer> total) {
        SecondChapter.MyList first = new SecondChapter.MyList(a);
        SecondChapter.MyList second = new SecondChapter.MyList(b);
        SecondChapter.MyList expected = new SecondChapter.MyList(total);
        assertThat(chapter.addition(first, second)).isEqualTo(expected);
    }

    @Test
    void testAdditionReverse() {
        testAdditionReverse(List.of(2, 5, 1), List.of(9, 6, 3), List.of(1, 2, 1, 4));
        testAdditionReverse(List.of(6, 5, 1), List.of(3), List.of(6, 5, 4));
    }

    private void testAdditionReverse(List<Integer> a, List<Integer> b, List<Integer> total) {
        SecondChapter.MyList first = new SecondChapter.MyList(a);
        SecondChapter.MyList second = new SecondChapter.MyList(b);
        SecondChapter.MyList expected = new SecondChapter.MyList(total);
        assertThat(chapter.additionReverse(first, second)).isEqualTo(expected);
    }

    @Test
    void testFindLoopStart() {
        SecondChapter.MyList.Node n1 = new SecondChapter.MyList.Node(1);
        SecondChapter.MyList.Node n2 = new SecondChapter.MyList.Node(2);
        SecondChapter.MyList.Node n3 = new SecondChapter.MyList.Node(3);
        SecondChapter.MyList.Node n4 = new SecondChapter.MyList.Node(4);
        SecondChapter.MyList.Node n5 = new SecondChapter.MyList.Node(5);
        SecondChapter.MyList.Node n6 = new SecondChapter.MyList.Node(6);
        SecondChapter.MyList.Node n7 = new SecondChapter.MyList.Node(7);
        n1.next = n2;
        n2.next = n3;
        n3.next = n4;
        n4.next = n5;
        n5.next = n6;
        n6.next = n7;
        n7.next = n4;
        assertThat(chapter.findLoopStart(new SecondChapter.MyList(n1)).data).isEqualTo(4);
    }

    @Test
    void testIsPalindrome() {
        assertThat(chapter.isPalindrome(new SecondChapter.MyList())).isTrue();
        assertThat(chapter.isPalindrome(new SecondChapter.MyList(List.of(1, 2, 3, 2, 1)))).isTrue();
        assertThat(chapter.isPalindrome(new SecondChapter.MyList(List.of(1, 5, 3, 2, 1)))).isFalse();
    }
}

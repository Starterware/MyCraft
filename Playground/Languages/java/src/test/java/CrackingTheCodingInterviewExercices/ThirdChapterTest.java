package CrackingTheCodingInterviewExercices;

import jdk.jfr.Description;
import org.junit.jupiter.api.Test;

import java.util.Stack;

import static com.google.common.truth.Truth.assertThat;

/**
 * Exercises from Cracking the code interview - Chapter 3 - Stacks and Queues
 */
public class ThirdChapterTest {
    @Test
    @Description("Exercise 1")
    void testThreeStackArray() {
        // Did this exercise TDD style
        ThirdChapter.MultiStack s = new ThirdChapter.MultiStack(3, 6);
        assertThat(s.top(0)).isNull();
        assertThat(s.isEmpty(0)).isTrue();
        assertThat(s.pop(0)).isNull();

        assertThat(s.push(0, 1)).isTrue();
        assertThat(s.push(4, 1)).isFalse();
        assertThat(s.push(-1, 1)).isFalse();

        assertThat(s.top(0)).isEqualTo(1);
        assertThat(s.isEmpty(0)).isFalse();
        assertThat(s.pop(0)).isEqualTo(1);
        assertThat(s.isEmpty(0)).isTrue();

        assertThat(s.top(-1)).isNull();
        assertThat(s.top(4)).isNull();
        assertThat(s.isEmpty(-1)).isTrue();
        assertThat(s.isEmpty(4)).isTrue();
        assertThat(s.pop(-1)).isNull();
        assertThat(s.pop(4)).isNull();

        s.push(0, 1);
        s.push(0, 2);
        assertThat(s.pop(0)).isEqualTo(2);
        assertThat(s.top(0)).isEqualTo(1);

        assertThat(s.top(1)).isNull();
        assertThat(s.isEmpty(1)).isTrue();
        assertThat(s.pop(1)).isNull();

        s.push(1, 10);
        assertThat(s.top(1)).isEqualTo(10);
        assertThat(s.isEmpty(1)).isFalse();
        assertThat(s.pop(1)).isEqualTo(10);
        assertThat(s.isEmpty(1)).isTrue();

        s.push(0, 2);
        assertThat(s.push(0, 3)).isFalse();
        assertThat(s.push(2, 100)).isTrue();
    }

    @Test
    @Description("Exercise 2")
    void testStackWithMin() {
        ThirdChapter.StackWithMin stack = new ThirdChapter.StackWithMin();
        assertThat(stack.min()).isEqualTo(Integer.MAX_VALUE);
        stack.push(5);
        assertThat(stack.min()).isEqualTo(5);
        stack.push(3);
        assertThat(stack.min()).isEqualTo(3);
        stack.push(3);
        assertThat(stack.min()).isEqualTo(3);
        stack.pop();
        assertThat(stack.min()).isEqualTo(3);
        stack.pop();
        assertThat(stack.min()).isEqualTo(5);
    }

    @Test
    @Description("Exercise 3")
    void testSetOfStacks() {
        ThirdChapter.SetOfStacks stack = new ThirdChapter.SetOfStacks();
        stack.push(1);
        stack.push(2);
        stack.push(3);
        assertThat(stack.peek()).isEqualTo(3);
        assertThat(stack.pop()).isEqualTo(3);
        assertThat(stack.peek()).isEqualTo(2);
        assertThat(stack.pop()).isEqualTo(2);
        assertThat(stack.pop()).isEqualTo(1);
        assertThat(stack.isEmpty()).isTrue();

        stack.push(1);
        stack.push(2);
        stack.push(3);
        assertThat(stack.pop(0)).isEqualTo(2);
        assertThat(stack.pop(0)).isEqualTo(1);
        assertThat(stack.pop(0)).isNull();
        assertThat(stack.pop()).isEqualTo(3);
        assertThat(stack.isEmpty()).isTrue();
        assertThat(stack.pop()).isNull();
    }

    @Test
    @Description("Exercise 4")
    void testHanoi() {
        testHanoi(1);
        testHanoi(2);
        testHanoi(3);
        testHanoi(4);
        testHanoi(5);
    }

    private void testHanoi(int size) {
        ThirdChapter chapter = new ThirdChapter();
        Stack<Integer> s1 = new Stack<>();
        Stack<Integer> s2 = new Stack<>();
        Stack<Integer> s3 = new Stack<>();
        for (int i = size; i > 0; i--) {
            s1.push(i);
        }
        chapter.hanoi(size, s1, s2, s3);
        for (int i = 1; i <= size; i++) {
            assertThat(s2.pop()).isEqualTo(i);
        }
    }

    @Test
    @Description("Exercise 5")
    void testMyQueue() {
        ThirdChapter.MyQueue<Integer> queue = new ThirdChapter.MyQueue<>();
        queue.add(1);
        assertThat(queue.isEmpty()).isFalse();
        queue.add(2);
        queue.add(3);
        assertThat(queue.peek()).isEqualTo(1);
        assertThat(queue.remove()).isEqualTo(1);
        queue.add(4);
        queue.add(5);
        assertThat(queue.size()).isEqualTo(4);
        assertThat(queue.remove()).isEqualTo(2);
        assertThat(queue.size()).isEqualTo(3);
        assertThat(queue.remove()).isEqualTo(3);
        assertThat(queue.remove()).isEqualTo(4);
        assertThat(queue.remove()).isEqualTo(5);
        assertThat(queue.isEmpty()).isTrue();
    }

    @Test
    @Description("Exercise 6")
    void testSortStack() {
        ThirdChapter chapter = new ThirdChapter();
        Stack<Integer> s = new Stack<>();
        s.push(5);
        s.push(1);
        s.push(3);
        s.push(4);
        s.push(2);
        chapter.sort(s);
        assertThat(s.pop()).isEqualTo(5);
        assertThat(s.pop()).isEqualTo(4);
        assertThat(s.pop()).isEqualTo(3);
        assertThat(s.pop()).isEqualTo(2);
        assertThat(s.pop()).isEqualTo(1);
    }

    @Test
    @Description("Exercise 7")
    void testAnimalQueue() {
        ThirdChapter.Animals animals = new ThirdChapter.Animals();
        animals.enqueue(new ThirdChapter.Animals.Cat("a"));
        animals.enqueue(new ThirdChapter.Animals.Cat("b"));
        animals.enqueue(new ThirdChapter.Animals.Dog("d"));
        animals.enqueue(new ThirdChapter.Animals.Cat("c"));
        animals.enqueue(new ThirdChapter.Animals.Dog("e"));
        animals.enqueue(new ThirdChapter.Animals.Cat("f"));
        assertThat(animals.dequeue().name).isEqualTo("a");
        assertThat(animals.dequeue().name).isEqualTo("b");
        assertThat(animals.dequeue().name).isEqualTo("d");
        assertThat(animals.dequeueDog().name).isEqualTo("e");
        assertThat(animals.dequeue().name).isEqualTo("c");
        assertThat(animals.dequeueCat().name).isEqualTo("f");
        assertThat(animals.dequeue()).isNull();
    }
}

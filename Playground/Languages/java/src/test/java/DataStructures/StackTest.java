package DataStructures;

import org.junit.jupiter.api.Test;

import java.util.Deque;
import java.util.LinkedList;
import java.util.Stack;

import static com.google.common.truth.Truth.assertThat;


public class StackTest {
    @Test
    void stack() {
        Stack<Integer> stack = new Stack<>();

        // How to add elements - O(1)
        stack.push(1);
        stack.push(2);
        stack.push(3);

        // Stack properties
        assertThat(stack.isEmpty()).isFalse();
        assertThat(stack.size()).isEqualTo(3);

        // Operations on the next item - O(1)
        assertThat(stack.peek()).isEqualTo(3);
        assertThat(stack.pop()).isEqualTo(3);

        // Searching for an element - O(N)
        assertThat(stack.search(5)).isEqualTo(-1);
        assertThat(stack.search(1)).isEqualTo(2); // position in the stack of the first hit

        // LIFO - last in first out
        stack.push(4);
        assertThat(stack.pop()).isEqualTo(4);
        assertThat(stack.pop()).isEqualTo(2);
        assertThat(stack.pop()).isEqualTo(1);

        // Stack properties
        assertThat(stack.isEmpty()).isTrue();
        assertThat(stack.size()).isEqualTo(0);
    }

    /**
     * It is recommended by the java documentation to use the Deque implementation for stacks.
     * ArrayDeque is part of the Java Collections Framework and is not written to be inherently thread safe.
     * This makes it faster.
     * However the negative side of Deque is that it allows more operations than needed.
     */
    @Test
    void deque() {
        Deque<Integer> stack = new LinkedList<>(); // or new ArrayDeque<>();

        // How to add elements - O(1)
        stack.push(1);
        stack.push(2);
        stack.push(3);

        // Stack properties
        assertThat(stack.isEmpty()).isFalse();
        assertThat(stack.size()).isEqualTo(3);

        // Operations on the next item - O(1)
        assertThat(stack.peek()).isEqualTo(3);
        assertThat(stack.pop()).isEqualTo(3);

        // Searching for an element - O(N)
        assertThat(stack.contains(5)).isEqualTo(false);
        assertThat(stack.contains(1)).isEqualTo(true);

        // LIFO - last in first out
        stack.push(4);
        assertThat(stack.pop()).isEqualTo(4);
        assertThat(stack.pop()).isEqualTo(2);
        assertThat(stack.pop()).isEqualTo(1);

        // Stack properties
        assertThat(stack.isEmpty()).isTrue();
        assertThat(stack.size()).isEqualTo(0);
    }
}

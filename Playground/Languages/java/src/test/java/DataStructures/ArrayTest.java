package DataStructures;

import org.junit.jupiter.api.Test;

import java.util.ArrayList;
import java.util.List;

import static com.google.common.truth.Truth.assertThat;
import static org.junit.jupiter.api.Assertions.assertThrows;

public class ArrayTest {
    /**
     * The initial capacity is of ten. The grow of the array is not specified but often it doubles.
     */
    @Test
    void ArrayList() {
        List<String> list = new ArrayList<>();

        // How to append elements - O(1) or O(n) if array is full
        list.add("key");
        list.add(1, "key2"); // Not efficient, shifts all values after the index
        list.addAll(List.of("key3", "key4"));

        // How to search elements - O(1)
        assertThat(list.get(0)).isEqualTo("key");
        assertThrows(IndexOutOfBoundsException.class, () -> list.get(5));
        assertThat(list.contains("key2")).isTrue(); // O(n)

        // List properties
        assertThat(list.size()).isEqualTo(4);
        assertThat(list.isEmpty()).isFalse();

        // How to loop
        int count = 0;
        for(var elem : list)
            count++;
        assertThat(count).isEqualTo(4);
    }
}

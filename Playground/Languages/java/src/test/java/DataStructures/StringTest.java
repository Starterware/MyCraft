package DataStructures;

import org.junit.jupiter.api.Test;

import static com.google.common.truth.Truth.assertThat;

public class StringTest {
    /**
     * StringBuffer and StringBuilder are almost the same except that the first one is thread safe.
     * There are some optimisations that are done for Java concatenation, it uses a string builder when the concat is
     * not in a loop. Ex: var test = "s" + "s2" + "s3"
     * In loops a builder is made in the loop statement. Don't forget that in java Strings are Immutable so a copy is
     * always needed when changing the String.
     * A string builder uses a simple array and keeps track of the end position.
      */
    @Test
    void StringBuffer() {
        StringBuilder builder = new StringBuilder();
        for (int i = 0; i < 10; i++) {
           builder.append(i).append(" ");
        }
        assertThat(builder.toString()).isEqualTo("0 1 2 3 4 5 6 7 8 9 ");
    }
}

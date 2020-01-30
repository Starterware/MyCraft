import annotations.Test;

public class WasRun extends TestCase {
    public boolean wasRun;
    public String log;

    public WasRun(String name) {
        super(name);
        log = "";
    }

    public void setUp() {
        log += "setUp ";
    }

    @Test
    public void testMethod() {
        this.wasRun = true;
        log += "testMethod ";
    }

    @Test
    public void testBrokenMethod() {
        throw new AssertionError();
    }

    public void tearDown() {
        log += "tearDown ";
    }
}

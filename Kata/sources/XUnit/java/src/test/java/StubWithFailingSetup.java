import annotations.Test;

public class StubWithFailingSetup extends TestCase {
    public StubWithFailingSetup(String name) {
        super(name);
    }

    @Override
    public void setUp() {
        throw new AssertionError();
    }

    @Test
    public void testMethod() {
        // do nothing
    }
}

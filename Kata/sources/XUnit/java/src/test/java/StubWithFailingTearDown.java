import annotations.Test;

public class StubWithFailingTearDown extends TestCase {
    public StubWithFailingTearDown(String name) {
        super(name);
    }

    @Override
    public void tearDown() {
        throw new AssertionError();
    }

    @Test
    public void testMethod() {
        // do nothing
    }
}

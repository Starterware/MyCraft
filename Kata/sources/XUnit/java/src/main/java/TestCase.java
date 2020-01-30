import java.lang.reflect.InvocationTargetException;

public class TestCase implements ITest {
    protected String name;

    public TestCase(String name) {
        this.name = name;
    }

    public void setUp() {}

    public void tearDown() {}

    public void run(TestResult result) {
        try {
            result.testStarted();
            setUp();
            getClass().getMethod(name).invoke(this);
            tearDown();
        } catch (Throwable t) {
            if (t instanceof InvocationTargetException) {
                InvocationTargetException ex = (InvocationTargetException)t;
                result.testFailed(name, ex.getTargetException().getStackTrace());
            } else {
                result.testFailed(name, t.getStackTrace());
            }
        }
    }
}

import annotations.Test;

import java.lang.reflect.Constructor;
import java.lang.reflect.Method;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class TestSuite implements ITest {
    List<ITest> tests = new ArrayList<>();

    public TestSuite() {}

    public TestSuite(Class<? extends TestCase> testCaseClass) {
        final List<Method> allMethods = new ArrayList<>(Arrays.asList(testCaseClass.getDeclaredMethods()));
        for (final Method method : allMethods) {
            if (method.isAnnotationPresent(Test.class)) {
                try {
                    Constructor<?> constructor = testCaseClass.getConstructor(String.class);
                    add((ITest) constructor.newInstance(method.getName()));
                } catch (Throwable t) {
                    add(new TestCase(method.getName())); // Should not happen - but at least an error will be reported per test
                }
            }
        }
    }

    public void add(ITest test) {
        tests.add(test);
    }

    public void run(TestResult result) {
        for (ITest test : tests) {
            test.run(result);
        }
    }
}

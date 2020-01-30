import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class TestResult {
    private int runCount;
    private int errorCount;
    private List<TestFailure> failures;

    public TestResult() {
        this.runCount = 0;
        this.errorCount = 0;
        this.failures = new ArrayList<>();
    }

    public void testStarted() {
        this.runCount += 1;
    }

    public String getSummary() {
        return String.format("%d run, %d failed", runCount, errorCount);
    }

    public void testFailed(String name, StackTraceElement[] stackTraceElements) {
        this.failures.add(new TestFailure(name, stackTraceElements));
        this.errorCount += 1;
    }

    public List<TestFailure> getFailedTests() {
        return failures;
    }

    public String report() {
        StringBuilder sb = new StringBuilder();
        sb.append(getSummary()).append("\n\n");
        for (TestFailure failure : failures) {
            sb.append(failure.getName()).append(" Failed:\n");
            String stack = Arrays.stream(failure.getStackTrace()).reduce("", (s, a) -> s + "\t" + a.toString() + "\n", String::concat);
            sb.append(stack).append("\n");
        }
        return sb.toString();
    }
}

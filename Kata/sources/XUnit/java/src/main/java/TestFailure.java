public class TestFailure {
    private String name;
    private StackTraceElement[] stackTrace;

    public TestFailure(String name, StackTraceElement[] stackTrace) {
        this.name = name;
        this.stackTrace = stackTrace;
    }

    public String getName() {
        return name;
    }

    public StackTraceElement[] getStackTrace() {
        return stackTrace;
    }
}

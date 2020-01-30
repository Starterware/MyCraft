import annotations.Test;

public class TestCaseTest extends TestCase {
    TestResult result;

    public TestCaseTest(String name) {
        super(name);
    }

    @Override
    public void setUp() {
        result = new TestResult();
    }

    @Test
    public void testTemplateMethod() {
        WasRun test = new WasRun("testMethod");
        test.run(result);
        assert (test.log.equals("setUp testMethod tearDown "));
    }

    @Test
    public void testResult() {
        WasRun test = new WasRun("testMethod");
        test.run(result);
        assert (result.getSummary().equals("1 run, 0 failed"));
        assert (result.getFailedTests().size() == 0);
    }

    @Test
    public void testFailedResult() {
        WasRun test = new WasRun("testBrokenMethod");
        test.run(result);
        assert (result.getSummary().equals("1 run, 1 failed"));
        assert (result.getFailedTests().get(0).getName().equals("testBrokenMethod"));
        assert (result.getFailedTests().get(0).getStackTrace()[0].getMethodName().equals("testBrokenMethod"));
    }

    @Test
    public void testMethodNotFound() {
        WasRun test = new WasRun("notExistingMethod");
        test.run(result);
        assert (result.getSummary().equals("1 run, 1 failed"));
        assert (result.getFailedTests().get(0).getName().equals("notExistingMethod"));
        assert (result.getFailedTests().get(0).getStackTrace() != null);
    }

    @Test
    public void testFailedResultFormatting() {
        result.testStarted();
        result.testFailed("testMethod", new Exception().getStackTrace());
        String output = result.report();
        assert (output.contains("1 run, 1 failed"));
        assert (output.contains("testMethod Failed:"));
        assert (output.contains("testFailedResultFormatting"));
    }

    @Test
    public void testSuite() {
        TestSuite suite = new TestSuite();
        suite.add(new WasRun("testMethod"));
        suite.add(new WasRun("testBrokenMethod"));
        suite.run(result);
        assert (result.getSummary().equals("2 run, 1 failed"));
        assert (result.getFailedTests().size() == 1);
    }

    @Test
    public void testSuiteOfTestSuite() {
        TestSuite parent = new TestSuite();
        TestSuite child = new TestSuite();
        child.add(new WasRun("testMethod"));
        parent.add(child);
        parent.run(result);
        assert (result.getSummary().equals("1 run, 0 failed"));
    }

    @Test
    public void testCreateTestSuiteFromTestClass() {
        TestSuite tests = new TestSuite(WasRun.class);
        tests.run(result);
        assert (result.getSummary().equals("2 run, 1 failed"));
    }

    @Test
    public void testFailedSetUp() {
        TestCase test = new StubWithFailingSetup("testMethod");
        test.run(result);
        assert (result.getSummary().equals("1 run, 1 failed"));
    }

    @Test
    public void testFailedTearDown() {
        TestCase test = new StubWithFailingTearDown("testMethod");
        test.run(result);
        assert (result.getSummary().equals("1 run, 1 failed"));
    }
}


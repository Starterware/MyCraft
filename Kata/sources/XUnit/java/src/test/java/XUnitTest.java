public class XUnitTest {
    static public void main(String[] args){
        TestResult result = new TestResult();
        TestSuite suite = new TestSuite(TestCaseTest.class);
        suite.run(result);
        System.out.println(result.report());
    }
}

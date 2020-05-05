## How to run the unit tests

In a command prompt (or shell), when in the Java folder, run the command: 
```
mvn test
```
It will build and run the test. 


## How to run the TexttestFicture

In a command prompt (or shell), when in the Java folder, run the command: 
```
mvn clean install
java -cp target/gilded-rose-kata-0.0.1-SNAPSHOT-tests.jar;target/gilded-rose-kata-0.0.1-SNAPSHOT.jar com.gildedrose.TexttestFixture
```

## How I did it

I simply use intellij to open the pom.xml and it allows to run the multiple tests and the main of the TexttestFicture.


## Remarks
* Maven and Java must be installed and the binary paths must be specified in the environment variables
* I used Maven 3.6.1 and Java 11.0.5
* If more information is needed to compile, please contact me.

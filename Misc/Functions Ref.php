<!--Taken from Codecademy's PHP classes. Go check 'em out.-->
<html>
	<head>
		<title>PHP functions reference. Taken from Codecademy.com</title>
    </head>
	<body>
    	<p>
	      	<?php
	        	// The code below creates the class
	        	class Person 
	        	{
		            // Creating some properties (variables tied to an object)
		            public $isAlive = true;
		            public $firstname;
		            public $lastname;
		            public $age;
		            
		            // Assigning the values
		            public function __construct($firstname, $lastname, $age) {
		              $this->firstname = $firstname;
		              $this->lastname = $lastname;
		              $this->age = $age;
		            }
		            
		            // Creating a method (function tied to an object)
		            public function greet() {
		              return "Hello, my name is " . $this->firstname . " " . $this->lastname . ". Nice to meet you! :-)";
		            }
	         	}
	          
	        	// Creating a new person called "boring 12345", who is 12345 years old ;-)
	        	$me = new Person('boring', '12345', 12345);
	        
		        // Printing out, what the greet method returns
		        echo $me->greet();
		        echo $me->isAlive; 
	        ?>
       	</p>
    </body>
</html>
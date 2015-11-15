/*
*	Using class extends
*
*	LU: 11/12/15
*/

class Cat extends Animal 
{
  speak() 
  {
     return this.name + " meows.";
  };
}

/* Test code

Test.describe('Fixed Tests', _ => {
  var cat = new Cat('Mr Whiskers');
  Test.assertEquals(cat.speak(),'Mr Whiskers meows.')
  cat = new Cat('Lamp');
  Test.assertEquals(cat.speak(),'Lamp meows.')
  cat = new Cat('$$Money Bags$$');
  Test.assertEquals(cat.speak(),'$$Money Bags$$ meows.')
});

*/
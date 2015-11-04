/*RemoveElements.js
*
*	Removes marked elements from a list. I decided to this the long handed way.
*	Perhaps not the most efficient.
*
*	Nov 3rd, 2015
*/

Array.prototype.remove_ = function(integer_list, values_list)
{
  var result = [];
  var val_len = values_list.length;
  var int_len = integer_list.length;
	var i, j, k = 0;
  
  for(i = 0; i < val_len; ++i)
  {
  	for(j = 0; j < int_len; ++j)
    {
    	if (integer_list[j] == values_list[i])
      	integer_list[j] = null;
    }
  }
  
  for(i = 0; i < int_len; ++i)
  {
  	if(integer_list[i] != null)
    {
    	result[k] = integer_list[i];
      ++k
    }
  }
  
  return result;
}

/* Test cases

Test.describe("Basic Tests",_=>{
l = new Array()

integer_list =  [1, 1, 2 ,3 ,1 ,2 ,3 ,4]
values_list = [1, 3]
Test.assertSimilar(l.remove_(integer_list, values_list), [2, 2, 4])

integer_list = [1, 1, 2 ,3 ,1 ,2 ,3 ,4, 4, 3 ,5, 6, 7, 2, 8]
values_list  = [1, 3, 4, 2]
Test.assertSimilar(l.remove_(integer_list, values_list), [5, 6 ,7 ,8])

integer_list = [8, 2, 7, 2, 3, 4, 6, 5, 4, 4, 1, 2 , 3]
values_list  = [2, 4, 3]
Test.assertSimilar(l.remove_(integer_list, values_list), [8, 7, 6, 5, 1])

integer_list = [4, 4, 2 , 3]
values_list  = [2, 2, 4, 3]
Test.assertSimilar(l.remove_(integer_list, values_list), [])

integer_list = []
values_list  = [2, 2, 4, 3]
Test.assertSimilar(l.remove_(integer_list, values_list), [])
})

*/
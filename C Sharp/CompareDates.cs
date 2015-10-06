/*CompareDates.cs
*
*	C# example on how to use DateTime.
*	LU: 10/04/15
*/

using System;

public static class Kata
{
  public static bool CheckCoupon(string enteredCode, string correctCode, string currentDate, string expirationDate)
  {
    int date_comparison;
  	DateTime current_dt = Convert.ToDateTime(currentDate);
    DateTime expire_dt = Convert.ToDateTime(expirationDate);
    //Console.WriteLine(dt);
        
    // Compare the dates
	date_comparison = DateTime.Compare(current_dt, expire_dt);	
    if(date_comparison <= 0)
    {
    	if(enteredCode == correctCode)
      	return true;
    }
    else
    	return false;
    
    // Should never reach here.
    Console.WriteLine("Something strange happened. Retry please.")
    return false;
  }
}
/*	ArrayAverage.cs
*
*	Gets average of an array and compares with a value.
*
*/

public class Kata
{
  public static bool BetterThanAverage(int[] ClassPoints, int YourPoints)
  {
		int i, avg = 0;
		int ArrLength = ClassPoints.Length;

		for (i = 0; i < ArrLength; i++)
			avg = avg + ClassPoints[i];
		avg = avg/ArrLength;
    
		return avg < YourPoints ? true : false;
  }
}
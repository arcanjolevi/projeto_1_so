package monitor_example;

public class Counter {
	private int count = 0;
	
	/**
	* Function: Increment the counter value
	* @return {void}
	* 
	* @precondition: none
	* @postcondition: Counter incremented
	*/
	public synchronized void increment() {
		count++;
	}	
	
	/**
	* Function: Returns the value of the counter
	* @return {int} counter value
	* 
	* @precondition: none
	* @postcondition: none
	*/
	public synchronized int getCount() {
		return count;
	}
}

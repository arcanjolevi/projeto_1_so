package packageMonitorExample;

public class Counter {
	private int count = 0;
	
	/**
	* Function: Increment the counter value
	* @returns {void}
	* 
	* @precondition: none
	* @postcondition: Counter incremented
	*/
	public synchronized void increment() {
		count++;
	}	
	
	/**
	* Function: Returns the value of the counter
	* @returns {int} counter value
	* 
	* @precondition: none
	* @postcondition: none
	*/
	public int getCount() {
		return count;
	}
}

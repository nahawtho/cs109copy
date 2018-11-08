// Problem7a.java
class Problem7a{
	public static void main(String[] args){
		int [] list = {3, 9, 6, 12, 23, -25, 54, 9, 0, -12, 27};
		System.out.println(list[getMaxIndex(list)]); // prints 54
		System.out.println(list[getMinIndex(list)]); // prints -25
	}
	static int getMaxIndex(int[] A){
		int i=1, maxindex = 0;
		while(i<(A.length)){
			if (A[i] > A[maxindex]) maxindex = i;
		i++;
}
		return maxindex;
	}

	static int getMinIndex(int[] A){
		int i=1, minindex = 0;
		while(i<(A.length)){
			if (A[i] < A[minindex]) minindex = i;
		i++;	
		}
		return minindex;
	}
}


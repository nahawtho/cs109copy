// Problem2f.java
class Problem2f{
	public static void main(String[] args){
		int[][] table = { {3, 9, 6, 12},
			{23, -25, 54},
			{0, -12, 27, 8, 16} };
		System.out.println(getMax(table)); // prints 54
	}
	static int getMax(int[][] A){
		int max = A[0][0];
		for (int i=0; i<3; i++){
			for (int j=0; j<A[i].length; j++){
				if (A[i][j] > max){max=A[i][j];}
			}
		}
		return max;
	}
	}

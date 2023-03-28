import java.util.Scanner;

public class coin_change {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		//memorization makes it efficient
		
		//time complexity for the problem using recursion would be 0(m^n)
		//But using DP it is reduced to o(m.n)
		
		
		
		
		Scanner sc=new Scanner(System.in);
		
		int n=sc.nextInt();
		
		int n1=sc.nextInt();
		
		
		int arr[]=new int[n1];
		
		for(int i=0; i<n1; i++) {
			arr[i]=sc.nextInt();
		}
		
		
		int ans=minCoin(n, arr);
		
		System.out.println(ans);

	}
	
	
	static int minCoin(int n, int a[]) {
		
		if(n==0)
			return 0;
		
		int ans=Integer.MAX_VALUE;
		
		
		for(int i=0; i<a.length; i++) {
			
			if(n-a[i]>=0) {
			
			int subAns=minCoin(n-a[i], a);
			
			if(subAns!=Integer.MAX_VALUE && subAns+1<ans) {
				ans=subAns+1;
			}
			
			}
			
		}
		
		
		return ans;
		
		
		
		
		
	}

}

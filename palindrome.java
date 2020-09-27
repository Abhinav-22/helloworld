public class Main
{
	public static void main(String[] args) {
		int r,s=0,temp,n;
		n=100;
		temp=n;
		while(n>0)
		{r=n%10;
		s=(s*10)+r;
		n=n/10;
		}
		if(temp==s)
        System.out.println("it is a palindrome");
        else
        System.out.println("Not a palindrome");
		}
}

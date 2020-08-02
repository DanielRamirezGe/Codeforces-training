import java.*
public class Problema_a 
{
	public static void main(String args[])
	{
		Scanner sc=new Scanner(System.in);
		Stack<Interge> pila=new Stack<Interger>();
		Queue<Interger> cola=new LinkedList<>();
		PriorityQueue pq
		int num=sc.nextInt();
		String cad=sc.NextLine();
		for(int i=0; i<num; i++)
		{
			cad=sc.NextLine();
			String [] arr=cad.split(" ");
			for(int i=0; i<arr.length; i++)
			{
				if(arr[i].length()==1)
				{
					if(arr[i]=="+" or arr[i]=='*' or arr[i]=='-')
					{
						int uno_cola=cola.remove();
						int dos_cola=cola.remove();
						int uno_pila=pila.pop();
						int dos_pila=pila.pop();
						int uno_pq=pq.remove();
						int dos_pq=pq.remove();
						if(arr[i]=="+")
						{
							pila.push(uno_pila+dos_pila);
							cola.add(uno_cola+dos_cola);
							pq.add(uno_pq+dos_pq);
						}
						if(arr[i]=="-")
						{
							pila.push(uno_pila-dos_pila);
							cola.add(uno_cola-dos_cola);
							pq.add(uno_pq-dos_pq);
						}
						if(arr[i]=='*')
						{
							pila.push(uno_pila*dos_pila);
							cola.add(uno_cola*dos_cola);
							pq.add(uno_pq*dos_pq);
						}
					}
					else
					{
						int a=Interger.paseInt(arr[i]);
						pila.push(a);
						cola.add(a);
						pq.add(a);
					}
				}
				else
				{
					int a=Interger.paseInt(arr[i]);
					pila.push(a);
					cola.add(a);
					pq.add(a);
				}
			}
			cad="";
			int a=pila.pop();
			int b=cola.remove();
			int c=pq.romove();
			System.out.println(a+" "+b+" "+c+"\n");
		}

	}
}
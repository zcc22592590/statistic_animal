#include<iostream>
#include<string>
using namespace std;
/*
int main()
{
	int n;
	cin>>n;
	string name[n+1], place[n+1];//�̧Ǭ��s��cin�ɭԪ��W�r�ƶq�a�I 
	int num[n+1];//�ͪ����ƶq��int��ƫ��Ӧs��
	string temp[n+1][n+1];//��z�n����ơAcolumn��0��G�a�I, �᭱�ѤU��column���O�G�ͪ�
	int i, j, k;
	
	for(i=0; i<n; i++)	cin >> name[i] >> num[i] >> place[i]; 
	
	cout<<"-------------------------"<<endl;
	
	//////////�N���ƪ��a�I���temp����0��//////////
	k=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<=k;j++)
		{
			if(place[i]==temp[j][0])//�p�G�a�I���ƴN���L 
				break;
		}
		if(j>k)		//��ܦ��s���a�I 
		{
			temp[j][0] = place[i];
			k++;//�a�I�`��+1 
		}
	}
	
	//////////�N�P�@�a�I�����ƪ��ͪ����temp�̭�//////////
	//////////�p�G�ͪ����ơA�N���L�åB��L���x�s�Ѽ�+1//////////
	//�{���X�j�P�W��W���x�s���Ʀa�I���覡�j�P�p��
	//�Ƶ�: temp�@��k�����O����F�誺�A�M���`�@��n+1�����
	
	int m = 1, s = 1;//m�q�@�}�l�A�@���s��ͪ��W�r���a��
	int a;
	int sum[k][n+1];//�x�s�ʪ��ƶq���@���}�C�A�`�@��k�Ӧa�I�M�̦hn�ذʪ�
	for(i=1; i<=k; i++)//�b�x�s�n�����P�a�I��
	{
		cout << temp[i][0] << ": ";
		for(j=0; j<n; j++)//�Ninput���Ҧ���ƨ̧Ǹ򭫽ƪ��a�I���
		{
			//�Ҧ���input����temp�����Ʀa�I����@���A�u�ninput���a�I��temp����
			//�N��input��name�ᱼtemp�o�ӤG���}�C�̭�
			if(temp[i][0] == place[j])//�p�G�a�I����(�N�O�s�s�ݦ��s�u���N��)
			{
				for(a=1; a<=m; a++)//�̧��ˬd�s��ͪ�����m���S����{�b�ǳƭn��i�Ӫ��ͪ��W����
				{
					if(name[j] != temp[i][a])//�p�G�ǳƭn��i�Ӫ��W�r������w�g�s�b�G���}�Ctemp�̭�������@�ӦW�r
					{
						temp[i][m] = name[j];//���N��o�ӷs���ͪ��W�r����x�s�Ϊ��G���}�Ctemp�̭�			
						s++;//�Ӧa�I���ͪ��`��+1//m��b�o��for�j��̭��|�����D�A�ҥH��@��s�ӹ�{�b�o��for�j��̩�m++���\��			
						continue;//��P�_���s���ͪ��W��A���|�s�W��temp�̭��A�N����ȧ����A�������Xfor�j�� 
					}
					if(name[j] == temp[i][a])//�p�G�ͪ��W�r�ۦP
					{
						break;//�������X�o��for�j��
					}
				}
				//m���_�l�Ȭ�1�A�C�o�{�P�a�I���s���ͪ��A�Nm++
				//�P�@�Ӧa�I�S�����ƪ��ͪ��`�Ƭ�m-1	
				if(s > m)	m = s;
				
			}
		}
		
		int b;
		for(b=1; b<m; b++)
		{
			if(b==1)
			{
				cout << temp[i][b] << " " ;
			}
			else
			{
				cout << ", " << temp[i][b] << " "  ;//��X�ͪ��W�r��ƶq
			}
			
		}
		cout << endl;
		
		//�C�����@�Ӧa�I���W�r�s��A�N��m���sassign��1�A�H�Q�U�@�Ӧa�I�~�򰵦P�˪���
		m = 1;
		s = 1;
	}
}
*/
int main()
{
	int i,j,g,n,k,m,h,a;
	cin>>n;
	string animal[n+1],place[n+1],total[n+1],animalsort[n+1],placesort[n+1],dif[n+1],combine[n+1][n+1];
	int num[n],flag[n],sum[n],count[n][n];
	for(i=0;i<n;i++)
	{
		cin>>animal[i]>>num[i]>>place[i];
		flag[i]=0;
		sum[i]=0;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			count[i][j]=0;
		}
	}
	
	/*�N���Ʀa�I�qplace��z�X�ө��placesort*/ 
	k=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<=k;j++)
		{
			if(place[i]==placesort[j])
				break;
		}
		if(j>k)
		{
			placesort[k]=place[i];
			k++;
		}
	}


	
	m=0;
	for(i=0;i<k;i++)
	{
		for(j=0;j<n;j++)
		{
			if(placesort[i]==place[j])
			{
				combine[m][0]=place[j];
				combine[m][1]=animal[j];
				m++;
			}
		}	

	} 

	for(i=0;i<k;i++)//k = 3
	{
		h=0;
		a=0;
		cout<<placesort[i]<<" : ";
		for(j=0;j<m;j++)
		{
			h=0;
			if(placesort[i]==combine[j][0])//�p�G�a�I�ۦP 
			{
				for(g=0;g<m;g++)//m = 7 
				{
					if(combine[j][1]==animal[g]&&combine[j][0]==place[g])//�p�G�ʪ��W�r�ۦP�B�a�I�ۦP 
					{
						h+=num[g];//�Ʀr�`�M��h�̭� 
						num[g]=0;//�[�L���Ʀr�k�s 
						
					}
				}
			}
			if(h!=0)
			{
				total[a]=combine[j][1];
				flag[a]=h;
				a++;
			} 
		}
		for(j=0;j<a;j++)
		{
			if(j==0)
				cout<<total[j]<<" "<<flag[j];
			else 
				cout<<", "<<total[j]<<" "<<flag[j];
		}
		cout<<endl;
	}
}








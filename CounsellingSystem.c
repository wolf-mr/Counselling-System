#include <stdio.h>
struct std{
    int s_id;
    float cut_off;
    int c[3];
};
void sort_student(struct std *student,int student_no){
    for(int i=0;i<student_no;i++){
        for(int j=i+1;j<student_no;j++){
            if(student[i].cut_off<student[j].cut_off){
                struct std temp=student[i];
                student[i]=student[j];
                student[j]=temp;
            }
        }
    }
}
void find_required_cut_off(struct std *student,int student_no,float *required_cut_off,int *seat){
    int i=0;
    while(i<student_no){
        for(int j=0;j<3;j++){
            if(seat[student[i].c[j]]>0){
                required_cut_off[student[i].c[j]-1]=student[i].cut_off;
                seat[student[i].c[j]]=-1;
                goto lable;
            }
        }
        lable:
        i++;
    }
}
void print(struct std *student,int student_no){
    for(int i=0;i<student_no;i++){
        printf("Student-%d %f C-%d C-%d C-%d\n",student[i].s_id,student[i].cut_off,student[i].c[0],student[i].c[1],student[i].c[2]);
    }
}
int main()
{
    int college,student_no;
    scanf("%d%d",&college,&student_no);
    int seat[college];
    float required_cut_off[college];
    struct std student[student_no];
    for(int i=0;i<college;i++){
        scanf("%d",&seat[i]);
    }
    for(int i=0;i<student_no;i++){
        scanf("%d %f %d %d %d",&student[i].s_id,&student[i].cut_off,&student[i].c[0],&student[i].c[1],&student[i].c[2]);
        //printf("%d ",i);
        
    }
    sort_student(student,student_no);
    find_required_cut_off(student,student_no,required_cut_off,seat);
    print(student,student_no);
    
    for(int i=0;i<college;i++){
        if(required_cut_off[i]==0){
            printf("C-%d :n/a\n",i+1);
            continue;
        }
        printf("C-%d :%0.2f\n",i+1,required_cut_off[i]);
    }
    
    return 0;
}

#include <stdio.h>
#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
#include <mqueue.h>

mqd_t msg_q;
struct mq_attr q_detail;
char buff[32];
int msg_prio;

int main(int argc, char const *argv[])
{
	q_detail.mq_flags = 0;
	q_detail.mq_maxmsg = 4;
	q_detail.mq_msgsize = 32;
	q_detail.mq_curmsgs = 0;

	msg_q= mq_open("/mqeos", O_RDONLY | O_CREAT, S_IRUSR | S_IWUSR, &q_detail);

	 mq_receive(msg_q, buff, sizeof(buff), &msg_prio);
	 printf("Received Message : %s\nMessage Prio : %d\n", buff, msg_prio);
//	 printf("Message Prio : %d\n", msg_prio);

	 mq_close(msg_q);

	 return 0;
}

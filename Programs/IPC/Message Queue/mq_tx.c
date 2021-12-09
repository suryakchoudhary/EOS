#include <stdio.h>
#include <fcntl.h>       
#include <sys/stat.h> 
#include <mqueue.h>
struct mq_attr q_detail;
mqd_t msg_q;
int main(int argc, char const *argv[])
{

		q_detail.mq_flags = 0;
		q_detail.mq_maxmsg = 4;   //Queue depth
		q_detail.mq_msgsize = 32; //Size for each msg
		q_detail.mq_curmsgs = 0;   //current message

	msg_q = mq_open("/mqeos", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR, &q_detail);

	mq_send(msg_q, "SENDING HELLO\n", sizeof("SENDING HELLO\n"), 0);

	mq_close(msg_q);

	return 0;
}

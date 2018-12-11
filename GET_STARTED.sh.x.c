#if 0
	shc Version 3.8.9b, Generic Script Compiler
	Copyright (c) 1994-2015 Francisco Rosales <frosal@fi.upm.es>

	shc -f GET_STARTED.sh 
#endif

static  char data [] = 
#define      tst2_z	19
#define      tst2	((&data[2]))
	"\056\214\236\224\156\175\331\031\225\366\322\103\166\020\126\125"
	"\001\160\201\072\304\320"
#define      tst1_z	22
#define      tst1	((&data[25]))
	"\113\261\127\135\220\321\271\353\255\036\137\110\030\104\163\216"
	"\220\142\301\373\334\237\253\004\273"
#define      chk2_z	19
#define      chk2	((&data[48]))
	"\177\036\234\140\331\241\017\075\313\016\157\016\007\040\376\026"
	"\047\003\164\045"
#define      msg2_z	19
#define      msg2	((&data[70]))
	"\150\054\065\200\164\173\264\162\147\100\012\273\221\211\270\222"
	"\013\223\313\210\343\357\050"
#define      lsto_z	1
#define      lsto	((&data[90]))
	"\235"
#define      opts_z	1
#define      opts	((&data[91]))
	"\206"
#define      text_z	101
#define      text	((&data[116]))
	"\114\062\054\330\002\253\145\035\366\026\164\331\123\177\130\361"
	"\074\251\131\151\336\201\321\247\007\120\105\272\252\375\251\075"
	"\171\232\076\175\321\314\352\377\313\307\165\310\050\021\211\223"
	"\266\321\115\015\111\216\203\227\340\303\116\127\143\075\125\226"
	"\062\026\377\232\260\053\236\017\030\021\101\364\235\111\357\133"
	"\042\360\030\377\006\104\155\010\300\260\300\271\245\324\003\273"
	"\204\053\254\061\313\140\353\046\242\173\357\167\202\114\366\146"
	"\062\151\170\316\146\057\055\347\141\251\365\271\104\252\217\317"
	"\306\125\274\303\241\356\360\172\360\233\340\016\222\367\202\154"
	"\112\002\304\073\076\156"
#define      chk1_z	22
#define      chk1	((&data[245]))
	"\027\171\364\322\104\035\254\354\213\061\217\210\063\203\076\363"
	"\341\114\103\356\037\121\233\077\035\301"
#define      pswd_z	256
#define      pswd	((&data[317]))
	"\137\177\113\001\155\073\173\136\327\134\154\152\123\357\326\236"
	"\361\233\332\060\012\157\330\127\206\122\113\110\133\016\317\272"
	"\216\033\274\374\126\067\132\056\224\307\231\347\267\160\206\250"
	"\013\006\312\221\171\061\163\042\024\307\016\114\044\064\136\124"
	"\143\265\171\344\062\242\243\027\211\241\026\101\355\330\361\260"
	"\337\273\101\130\355\265\173\002\174\211\116\240\275\255\365\041"
	"\142\157\005\225\022\251\254\233\112\303\334\070\234\315\350\173"
	"\211\052\324\167\340\117\171\134\330\310\375\225\165\363\267\327"
	"\143\274\155\165\146\031\021\261\335\356\351\172\274\322\365\106"
	"\374\311\276\334\030\067\071\361\000\067\207\165\053\076\115\216"
	"\373\273\004\141\325\026\022\262\004\374\054\301\316\042\007\312"
	"\353\306\247\004\376\341\365\376\030\175\164\103\273\302\322\266"
	"\175\326\030\122\354\053\005\361\047\061\263\365\124\272\300\077"
	"\201\147\104\177\111\072\175\141\267\362\245\163\264\170\052\062"
	"\116\102\204\073\156\211\055\225\273\340\212\017\233\112\117\034"
	"\262\224\233\373\317\031\135\206\013\003\372\277\173\044\361\312"
	"\147\166\006\325\000\063\152\273\023\365\313\256\100\033\313\362"
	"\260\146\356\177\177\114\006\212\120\000\112\314\044\074\226\213"
	"\262\235\140\263\320\312\157\344\300\073\223\000\126\136\363\007"
	"\305\140\331\026\320\262\155\127\004\270\237\140\307\157\033\125"
	"\212\327\121\341\017\254\020\243\163\251\213\052\031\021\323\045"
	"\162\255\073"
#define      shll_z	10
#define      shll	((&data[608]))
	"\232\343\303\165\353\117\103\074\136\070\315\144"
#define      xecc_z	15
#define      xecc	((&data[619]))
	"\137\160\022\115\230\137\250\327\300\062\142\110\113\333\124\050"
	"\251\340"
#define      rlax_z	1
#define      rlax	((&data[637]))
	"\106"
#define      msg1_z	42
#define      msg1	((&data[638]))
	"\225\050\363\001\203\370\177\371\351\100\210\313\001\153\203\375"
	"\331\107\232\016\125\257\200\136\341\002\222\314\245\021\313\077"
	"\360\356\070\075\275\213\017\202\220\317\173\045\153\356\316\366"
	"\031\350"
#define      date_z	1
#define      date	((&data[688]))
	"\007"
#define      inlo_z	3
#define      inlo	((&data[689]))
	"\035\112\022"/* End of data[] */;
#define      hide_z	4096
#define DEBUGEXEC	0	/* Define as 1 to debug execvp calls */
#define TRACEABLE	0	/* Define as 1 to enable ptrace the executable */

/* rtc.c */

#include <sys/stat.h>
#include <sys/types.h>

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

/* 'Alleged RC4' */

static unsigned char stte[256], indx, jndx, kndx;

/*
 * Reset arc4 stte. 
 */
void stte_0(void)
{
	indx = jndx = kndx = 0;
	do {
		stte[indx] = indx;
	} while (++indx);
}

/*
 * Set key. Can be used more than once. 
 */
void key(void * str, int len)
{
	unsigned char tmp, * ptr = (unsigned char *)str;
	while (len > 0) {
		do {
			tmp = stte[indx];
			kndx += tmp;
			kndx += ptr[(int)indx % len];
			stte[indx] = stte[kndx];
			stte[kndx] = tmp;
		} while (++indx);
		ptr += 256;
		len -= 256;
	}
}

/*
 * Crypt data. 
 */
void arc4(void * str, int len)
{
	unsigned char tmp, * ptr = (unsigned char *)str;
	while (len > 0) {
		indx++;
		tmp = stte[indx];
		jndx += tmp;
		stte[indx] = stte[jndx];
		stte[jndx] = tmp;
		tmp += stte[indx];
		*ptr ^= stte[tmp];
		ptr++;
		len--;
	}
}

/* End of ARC4 */

/*
 * Key with file invariants. 
 */
int key_with_file(char * file)
{
	struct stat statf[1];
	struct stat control[1];

	if (stat(file, statf) < 0)
		return -1;

	/* Turn on stable fields */
	memset(control, 0, sizeof(control));
	control->st_ino = statf->st_ino;
	control->st_dev = statf->st_dev;
	control->st_rdev = statf->st_rdev;
	control->st_uid = statf->st_uid;
	control->st_gid = statf->st_gid;
	control->st_size = statf->st_size;
	control->st_mtime = statf->st_mtime;
	control->st_ctime = statf->st_ctime;
	key(control, sizeof(control));
	return 0;
}

#if DEBUGEXEC
void debugexec(char * sh11, int argc, char ** argv)
{
	int i;
	fprintf(stderr, "shll=%s\n", sh11 ? sh11 : "<null>");
	fprintf(stderr, "argc=%d\n", argc);
	if (!argv) {
		fprintf(stderr, "argv=<null>\n");
	} else { 
		for (i = 0; i <= argc ; i++)
			fprintf(stderr, "argv[%d]=%.60s\n", i, argv[i] ? argv[i] : "<null>");
	}
}
#endif /* DEBUGEXEC */

void rmarg(char ** argv, char * arg)
{
	for (; argv && *argv && *argv != arg; argv++);
	for (; argv && *argv; argv++)
		*argv = argv[1];
}

int chkenv(int argc)
{
	char buff[512];
	unsigned long mask, m;
	int l, a, c;
	char * string;
	extern char ** environ;

	mask  = (unsigned long)&chkenv;
	mask ^= (unsigned long)getpid() * ~mask;
	sprintf(buff, "x%lx", mask);
	string = getenv(buff);
#if DEBUGEXEC
	fprintf(stderr, "getenv(%s)=%s\n", buff, string ? string : "<null>");
#endif
	l = strlen(buff);
	if (!string) {
		/* 1st */
		sprintf(&buff[l], "=%lu %d", mask, argc);
		putenv(strdup(buff));
		return 0;
	}
	c = sscanf(string, "%lu %d%c", &m, &a, buff);
	if (c == 2 && m == mask) {
		/* 3rd */
		rmarg(environ, &string[-l - 1]);
		return 1 + (argc - a);
	}
	return -1;
}

#if !defined(TRACEABLE)

#define _LINUX_SOURCE_COMPAT
#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

#if !defined(PTRACE_ATTACH) && defined(PT_ATTACH)
#	define PTRACE_ATTACH	PT_ATTACH
#endif
void untraceable(char * argv0)
{
	char proc[80];
	int pid, mine;

	switch(pid = fork()) {
	case  0:
		pid = getppid();
		/* For problematic SunOS ptrace */
#if defined(__FreeBSD__)
		sprintf(proc, "/proc/%d/mem", (int)pid);
#else
		sprintf(proc, "/proc/%d/as",  (int)pid);
#endif
		close(0);
		mine = !open(proc, O_RDWR|O_EXCL);
		if (!mine && errno != EBUSY)
			mine = !ptrace(PTRACE_ATTACH, pid, 0, 0);
		if (mine) {
			kill(pid, SIGCONT);
		} else {
			perror(argv0);
			kill(pid, SIGKILL);
		}
		_exit(mine);
	case -1:
		break;
	default:
		if (pid == waitpid(pid, 0, 0))
			return;
	}
	perror(argv0);
	_exit(1);
}
#endif /* !defined(TRACEABLE) */

char * xsh(int argc, char ** argv)
{
	char * scrpt;
	int ret, i, j;
	char ** varg;
	char * me = argv[0];

	stte_0();
	 key(pswd, pswd_z);
	arc4(msg1, msg1_z);
	arc4(date, date_z);
	if (date[0] && (atoll(date)<time(NULL)))
		return msg1;
	arc4(shll, shll_z);
	arc4(inlo, inlo_z);
	arc4(xecc, xecc_z);
	arc4(lsto, lsto_z);
	arc4(tst1, tst1_z);
	 key(tst1, tst1_z);
	arc4(chk1, chk1_z);
	if ((chk1_z != tst1_z) || memcmp(tst1, chk1, tst1_z))
		return tst1;
	ret = chkenv(argc);
	arc4(msg2, msg2_z);
	if (ret < 0)
		return msg2;
	varg = (char **)calloc(argc + 10, sizeof(char *));
	if (!varg)
		return 0;
	if (ret) {
		arc4(rlax, rlax_z);
		if (!rlax[0] && key_with_file(shll))
			return shll;
		arc4(opts, opts_z);
		arc4(text, text_z);
		arc4(tst2, tst2_z);
		 key(tst2, tst2_z);
		arc4(chk2, chk2_z);
		if ((chk2_z != tst2_z) || memcmp(tst2, chk2, tst2_z))
			return tst2;
		/* Prepend hide_z spaces to script text to hide it. */
		scrpt = malloc(hide_z + text_z);
		if (!scrpt)
			return 0;
		memset(scrpt, (int) ' ', hide_z);
		memcpy(&scrpt[hide_z], text, text_z);
	} else {			/* Reexecute */
		if (*xecc) {
			scrpt = malloc(512);
			if (!scrpt)
				return 0;
			sprintf(scrpt, xecc, me);
		} else {
			scrpt = me;
		}
	}
	j = 0;
	varg[j++] = argv[0];		/* My own name at execution */
	if (ret && *opts)
		varg[j++] = opts;	/* Options on 1st line of code */
	if (*inlo)
		varg[j++] = inlo;	/* Option introducing inline code */
	varg[j++] = scrpt;		/* The script itself */
	if (*lsto)
		varg[j++] = lsto;	/* Option meaning last option */
	i = (ret > 1) ? ret : 0;	/* Args numbering correction */
	while (i < argc)
		varg[j++] = argv[i++];	/* Main run-time arguments */
	varg[j] = 0;			/* NULL terminated array */
#if DEBUGEXEC
	debugexec(shll, j, varg);
#endif
	execvp(shll, varg);
	return shll;
}

int main(int argc, char ** argv)
{
#if DEBUGEXEC
	debugexec("main", argc, argv);
#endif
#if !defined(TRACEABLE)
	untraceable(argv[0]);
#endif
	argv[1] = xsh(argc, argv);
	fprintf(stderr, "%s%s%s: %s\n", argv[0],
		errno ? ": " : "",
		errno ? strerror(errno) : "",
		argv[1] ? argv[1] : "<null>"
	);
	return 1;
}

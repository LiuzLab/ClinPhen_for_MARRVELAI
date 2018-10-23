#if 0
	shc Version 3.8.9b, Generic Script Compiler
	Copyright (c) 1994-2015 Francisco Rosales <frosal@fi.upm.es>

	shc -f ClinPhen.sh 
#endif

static  char data [] = 
#define      inlo_z	3
#define      inlo	((&data[0]))
	"\063\317\115"
#define      tst1_z	22
#define      tst1	((&data[4]))
	"\077\353\312\370\261\256\000\162\227\204\355\110\042\005\004\024"
	"\143\150\235\265\104\166\033"
#define      xecc_z	15
#define      xecc	((&data[27]))
	"\236\262\160\335\222\056\366\311\366\154\320\251\235\124\004\301"
	"\325"
#define      chk1_z	22
#define      chk1	((&data[43]))
	"\230\140\001\315\125\004\323\122\135\240\164\106\002\222\133\307"
	"\114\057\044\075\363\162\262\150\157\044\052"
#define      msg2_z	19
#define      msg2	((&data[72]))
	"\321\255\160\171\246\323\150\310\300\217\251\113\157\364\251\354"
	"\314\210\357\240\307\316\211"
#define      lsto_z	1
#define      lsto	((&data[93]))
	"\227"
#define      rlax_z	1
#define      rlax	((&data[94]))
	"\072"
#define      opts_z	1
#define      opts	((&data[95]))
	"\252"
#define      text_z	68
#define      text	((&data[103]))
	"\242\304\126\167\133\143\167\305\016\132\140\147\103\075\105\034"
	"\364\260\071\213\005\225\342\256\003\071\363\121\203\040\232\344"
	"\356\242\144\277\040\106\364\041\047\107\170\136\207\212\317\156"
	"\201\055\053\330\170\231\377\025\154\045\226\110\360\216\017\327"
	"\077\100\221\106\245\013\153\265\337\142\062\015\313\347\062\366"
	"\174\266\172\115\144\110\327"
#define      tst2_z	19
#define      tst2	((&data[186]))
	"\364\103\110\243\267\336\014\142\222\143\337\101\235\201\011\321"
	"\113\272\245\356\220\370"
#define      shll_z	10
#define      shll	((&data[206]))
	"\176\162\003\142\326\026\135\323\015\045\215\316"
#define      chk2_z	19
#define      chk2	((&data[217]))
	"\103\060\124\035\030\315\315\344\332\032\175\241\077\201\072\143"
	"\214\134\072\253\227"
#define      pswd_z	256
#define      pswd	((&data[241]))
	"\374\332\367\104\235\060\206\214\174\066\333\143\333\342\351\025"
	"\035\256\172\261\237\031\342\035\355\362\342\372\107\373\367\133"
	"\302\144\237\140\224\045\355\021\134\311\164\067\254\135\115\311"
	"\014\307\173\254\341\136\311\317\120\253\312\227\247\301\363\152"
	"\046\222\313\273\270\270\314\025\201\101\114\055\237\232\367\253"
	"\142\163\130\103\321\041\023\042\315\336\271\165\240\254\337\307"
	"\077\253\202\367\144\117\014\346\221\131\024\060\363\014\334\125"
	"\177\064\231\121\125\255\163\043\214\054\230\054\331\170\363\031"
	"\044\166\020\210\306\035\157\127\167\203\207\153\217\143\300\017"
	"\230\132\140\356\007\323\021\223\000\251\300\331\041\263\362\105"
	"\052\003\316\360\041\075\107\231\301\317\004\121\063\304\140\313"
	"\037\301\271\047\224\312\273\224\164\173\156\226\057\141\334\131"
	"\145\252\111\207\350\221\040\251\140\045\372\223\352\133\136\011"
	"\034\030\060\261\343\354\106\127\147\265\355\227\026\311\361\174"
	"\164\072\004\134\314\045\006\054\112\000\300\064\134\037\075\170"
	"\067\156\052\033\132\160\162\302\045\137\131\074\051\112\270\235"
	"\205\275\371\057\320\164"
#define      msg1_z	42
#define      msg1	((&data[503]))
	"\113\223\231\311\241\072\313\337\032\137\026\013\157\267\170\144"
	"\014\034\062\322\066\135\206\275\275\353\176\314\201\271\224\376"
	"\105\032\126\162\337\373\073\122\025\200\331\301\020\372\061\270"
	"\357\165\000\047\336"
#define      date_z	1
#define      date	((&data[553]))
	"\303"/* End of data[] */;
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

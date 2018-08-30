#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <pwd.h>
#include <grp.h>

int	ft_ls_aff(DIR* dir)
{
	struct dirent* dirRead;

	dirRead = readdir(dir);
	while ((dirRead = readdir(dir)) && dirRead->d_name[0] == '.')
			printf("%s\n", dirRead->d_name);
	return (0);
}

void	ft_ls_l(struct dirent* dirRead, t_lst list)
{
	struct stat buf;
	struct passwd *uid;
	struct group *guid;

	if (stat(dirRead->d_name, &buf) == -1)
	{
		perror("");
		exit(1);
	}
//SOCKET
	//repository
	if ((buf.st_mode & S_IFMT) == S_IFDIR)
		printf("d");
	//file
	else if ((buf.st_mode & S_IFMT) == S_IFREG)
		printf("-");

//RIGHT
	//user
	if ((buf.st_mode & S_IRWXU) == S_IRWXU)
		printf("rwx");
	else { 
		if ((buf.st_mode & S_IRUSR) == S_IRUSR)
			printf("r");
		else printf("-");
		if ((buf.st_mode & S_IWUSR) == S_IWUSR)
			printf("w");
		else printf("-");
		if ((buf.st_mode & S_IXUSR) == S_IXUSR)
			printf("x");
		else printf("-");}
	//group
	if ((buf.st_mode & S_IRWXG) == S_IRWXG)
		printf("rwx");
	else {
		if ((buf.st_mode & S_IRGRP) == S_IRGRP)
			printf("r");
		else printf("-");
		if ((buf.st_mode & S_IWGRP) == S_IWGRP)
			printf("w");
		else printf("-");
		if ((buf.st_mode & S_IXGRP) == S_IXGRP)
			printf("x");
		else printf("-");}
	//other
	if ((buf.st_mode & S_IRWXO) == S_IRWXO)
		printf("rwx");
	else {
		if ((buf.st_mode & S_IROTH) == S_IROTH)
			printf("r");
		else printf("-");
		if ((buf.st_mode & S_IWOTH) == S_IWOTH)
			printf("w");
		else printf("-");
		if ((buf.st_mode & S_IXOTH) == S_IXOTH)
			printf("x");
		else printf("-");}
	printf("  ");

//LINK
	printf("%c", (char)(buf.st_nlink + 48));
	printf(" ");

//UID + GUID
	//uid
	uid = getpwuid(buf.st_uid);
	printf("%s", uid->pw_name);
	printf(" ");

	//guid
	guid = getgrgid(buf.st_gid);
	printf("%s", guid->gr_name);
	printf(" ");

//TAILLE BLOC
	printf("%lld" ,buf.st_size);
	printf(" ");


//TIME
	printf("%ld", buf.st_atime);
	printf(" ");

}

int main(int argc, char **argv)
{
	DIR* dir;
	struct dirent* dirRead;
	//struct stat buf;

	dir = NULL;
	dirRead = NULL;	
		
	if (argc == 1)
	{
		argv[1] = "./";
		dir = opendir("./");	
	}
	else
	{
		dir = opendir(argv[1]);
	}


	if (dir == NULL)
	{
		printf("ls: %s: %s\n", argv[1], strerror(errno));
		exit(1);
	}
	printf("File ouvert\n\n\n");


	while ((dirRead = readdir(dir)))
	{
		while (dirRead->d_name[0] == '.')
			dirRead = readdir(dir);
		ft_ls_aff(dir);
		ft_ls_l(dirRead);
		printf("%s\n", dirRead->d_name);
	}


	if (closedir(dir) == -1)
		exit(-1);
	printf("\n\nFile ferme\n");
	


}

void elf_osabi(const unsigned char *buffer)
{
	const char *os_table[19] = {
		"UNIX - System V",
		"UNIX - HP-UX",
		"UNIX - NetBSD",
		"UNIX - GNU",
		"<unknown: 4>",
		"<unknown: 5>",
		"UNIX - Solaris",
		"UNIX - AIX",
		"UNIX - IRIX",
		"UNIX - FreeBSD",
		"UNIX - Tru64",
		"Novell - Modesto",
		"UNIX - OpenBSD",
		"VMS - OpenVMS",
		"HP - Non-Stop Kernel",
		"AROS",
		"FenixOS",
		"Nuxi CloudABI",
		"Stratus Technologies OpenVOS"
	};

	printf("  %-34s ", "OS/ABI:");

	if (buffer[EI_OSABI] < 19)
		printf("%s\n", os_table[(unsigned int) buffer[EI_OSABI]]);
	else
		printf("<unknown: %x>\n", buffer[EI_OSABI]);
}

/**
 * elf_abivers - print ELF ABI version
 * @buffer: the ELF header
 */
void elf_abivers(const unsigned char *buffer)
{
	printf("  %-34s %u\n", "ABI Version:", buffer[EI_ABIVERSION]);
}

/**
 * elf_type - print ELF type
 * @buffer: the ELF header
 * @big_endian: endianness (big endian if non-zero)
 */
void elf_type(const unsigned char *buffer, int big_endian)
{
	char *type_table[5] = {
		"NONE (No file type)",
		"REL (Relocatable file)",
		"EXEC (Executable file)",
		"DYN (Shared object file)",
		"CORE (Core file)"
	};
	unsigned int type;

	printf("  %-34s ", "Type:");

	if (big_endian)
		type = 0x100 * buffer[16] + buffer[17];
	else
		type = 0x100 * buffer[17] + buffer[16];

	if (type < 5)
		printf("%s\n", type_table[type]);
	else if (type >= ET_LOOS && type <= ET_HIOS)
		printf("OS Specific: (%4x)\n", type);
	else if (type >= ET_LOPROC && type <= ET_HIPROC)
		printf("Processor Specific: (%4x)\n", type);
	else
		printf("<unknown: %x>\n", type);
}

/**
 * elf_entry - print entry point address
 * @buffer: string containing the entry point address
 * @bit_mode: bit mode (32 or 64)
 * @big_endian: endianness (big endian if non-zero)
 */
void elf_entry(const unsigned char *buffer, size_t bit_mode, int big_endian)
{
	int address_size = bit_mode / 8;

	printf("  %-34s 0x", "Entry point address:");

	if (big_endian)
	{
		while (address_size && !*(buffer))
			--address_size, ++buffer;

		printf("%x", *buffer & 0xff);

		while (--address_size > 0)
			printf("%02x", *(++buffer) & 0xff);
	}
	else
	{
		buffer += address_size;

		while (address_size && !*(--buffer))
			--address_size;

		printf("%x", *buffer & 0xff);

		while (--address_size > 0)
			printf("%02x", *(--buffer) & 0xff);
	}

	printf("\n");
}

/**
 * main - copy a file's contents to another file
 * @argc: the argument count
 * @argv: the argument values
 *
 * Return: Always 0
 */
int main(int argc, const char *argv[])
{
	unsigned char buffer[18];
	unsigned int bit_mode;
	int big_endian;
	int fd;

	if (argc != 2)
	{
		write(STDERR_FILENO, "Usage: elf_header elf_filename\n", 31);
		exit(98);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		write(STDERR_FILENO, "Error: Can't read from file\n", 28);
		exit(98);
	}

	_read(fd, (char *) buffer, 18);

	elf_magic(buffer);
	bit_mode = elf_class(buffer);
	big_endian = elf_data(buffer);
	elf_version(buffer);
	elf_osabi(buffer);
	elf_abivers(buffer);
	elf_type(buffer, big_endian);

	lseek(fd, 24, SEEK_SET);
	_read(fd, (char *) buffer, bit_mode / 8);

	elf_entry(buffer, bit_mode, big_endian);

	_close(fd);

	return (0);
}

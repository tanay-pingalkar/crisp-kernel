kernel := build/kernel.bin
iso := build/minimal-os.iso

linker_script := src/linker.ld
grub_cfg := src/grub.cfg
assembly_source_files := $(shell find src/ -name *.asm)
assembly_object_files := $(patsubst src/%.asm, \
	build/%.o, $(assembly_source_files))

c_source_files := $(shell find src/ -name *.c)
c_object_files := $(patsubst src/%.c, \
	build/%.o, $(c_source_files))


.PHONY: clean run iso

clean:
	@rm -r build

run: $(iso)
	@qemu-system-x86_64 -cdrom $(iso)

iso: $(iso)

$(iso): $(kernel) $(grub_cfg)
	@mkdir -p build/isofiles/boot/grub
	@cp $(kernel) build/isofiles/boot/kernel.bin
	@cp $(grub_cfg) build/isofiles/boot/grub
	@grub-mkrescue -o $(iso) build/isofiles 2> /dev/null
	@rm -r build/isofiles

$(kernel): $(c_object_files) $(assembly_object_files) $(linker_script)
	@ld -n -T $(linker_script) -o $(kernel) $(c_object_files)  $(assembly_object_files) 

# compile assembly files
build/%.o: src/%.asm
	@mkdir -p $(shell dirname $@)
	@nasm -felf64 $< -o $@


build/%.o: src/%.c
	@mkdir -p $(shell dirname $@)
	@gcc -c  $< -o $@
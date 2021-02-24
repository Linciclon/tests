debug:
	riscv64-unknown-elf-gdb -x gdbrc

launch: image
	renode icicle.resc

clean:
	@rm -f *.elf


.PHONY: all clean

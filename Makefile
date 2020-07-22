include config.mk

default_target: LibreTextus

options:
	@echo LibreTextus build options:
	@echo "CPPFLAGS		= $(CPPFLAGS)"
	@echo "LDFLAGS		= $(LDFLAGS)"
	@echo "CC					= $(CC)"

build_dir:
	@if [ ! -d "$(ODIR)" ]; then \
		printf "Create directory $(green)$(ODIR)$(sgr0)\n"; \
		mkdir $(ODIR); \
	fi

data_dir: build_dir
	@printf "Copy directory $(green)data$(sgr0) to $(green)$(ODIR)$(sgr0)\n"
	@cp -r data build

locales: build_dir
	@if [ ! -d "$(ODIR)/locale/" ]; then \
		printf "Create directory $(green)$(ODIR)/locale$(sgr0)\n"; \
		mkdir $(ODIR)/locale; \
	fi
	@for po_file in po/*.po ; do \
		locale_name=$$(basename $$po_file .po); \
		if [ ! -d "$(ODIR)/locale/$$locale_name" ]; then \
			printf "Create directory $(green)$(ODIR)/locale/$${locale_name}/LC_MESSAGES$(sgr0)\n"; \
			mkdir -p $(ODIR)/locale/$${locale_name}/LC_MESSAGES; \
		fi; \
		printf "Build $(green)$$po_file$(sgr0)\n"; \
		msgfmt --check --output-file $(ODIR)/locale/$${locale_name}/LC_MESSAGES/libretextus.mo $$po_file; \
	done

$(ODIR)/%.o: src/%.cpp
	@printf "Build $(green)$^$(sgr0)\n"
	@$(CC) -c $^ -o $@ $(CPPFLAGS)

LibreTextus: build_dir data_dir locales $(OBJ)
	@printf "Build $(green)$@$(sgr0)\n"
	@$(CC) -o $(ODIR)/$@ src/main.cpp $(OBJ) $(LDFLAGS) $(CPPFLAGS)
	@printf "Build Finished!\n"

clean:
	@printf "Remove directory $(green)build$(sgr0)\n"
	@rm -rf build

install:
	@printf "Create directory $(green)$(DESTDIR)/share/LibreTextus$(sgr0)\n"
	@mkdir -p $(DESTDIR)/share/LibreTextus/
	@printf "Copy executable $(green)LibreTextus$(sgr0) to $(green)$(DESTDIR)/share/LibreTextus$(sgr0)\n"
	@cp build/LibreTextus $(DESTDIR)/share/LibreTextus/
	@printf "Copy directory $(green)build/data$(sgr0) to $(green)$(DESTDIR)/share/LibreTextus$(sgr0)\n"
	@cp -r build/data $(DESTDIR)/share/LibreTextus/
	@printf "Copy $(green)libretextus.desktop$(sgr0) to $(green)$(DESTDIR)/share/LibreTextus$(sgr0)\n"
	@cp libretextus.desktop $(DESTDIR)/share/LibreTextus
	@printf "Copy directory $(green)build/locale$(sgr0) to $(green)$(DESTDIR)/share/LibreTextus$(sgr0)\n"
	@cp -r build/locale $(DESTDIR)/share/LibreTextus/
	@printf "Create symbolic link $(green)$(DESTDIR)/bin/LibreTextus$(sgr0) of executable $(green)LibreTextus$(sgr0)\n"
	@mkdir -p $(DESTDIR)/bin
	@ln -sf $(DESTDIR)/share/LibreTextus/LibreTextus $(DESTDIR)/bin/LibreTextus
	@printf "Copy $(green)manpage$(sgr0) to $(green)$(MANPREFIX)/LibreTextus.1$(sgr0)\n"
	@mkdir -p $(MANPREFIX)
	@cp doc/LibreTextus.1 $(MANPREFIX)/LibreTextus.1

uninstall:
	@printf "Remove directory $(green)$(DESTDIR)/share/LibreTextus$(sgr0)\n"
	@rm -rf $(DESTDIR)/share/LibreTextus
	@printf "Remove symbolic link $(green)$(DESTDIR)/bin/LibreTextus$(sgr0)\n"
	@rm $(DESTDIR)/bin/LibreTextus
	@printf "Remove manpage $(green)$(MANPREFIX)/LibreTextus.1$(sgr0)\n"
	@rm $(MANPREFIX)/LibreTextus.1

.PHONY: options libretextus LibreTextus data_dir locales clean install

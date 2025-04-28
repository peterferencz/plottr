.PHONY: docs
.DEFAULT: docs
docs: ./src/specification.tex
	mkdir -p ./working
	pdflatex -halt-on-error -output-directory=./working ./src/specification.tex

.PHONY: uml
uml: uml/*.pu
	plantuml uml/*.pu -o ../res/uml

.PHONY: clean
clean:
	rm -r ./working
	rm -r ./res/uml
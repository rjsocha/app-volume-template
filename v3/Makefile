REGISTRY = wyga/deploy-template:v3
PLATFORM = linux/amd64,linux/arm64/v8
BUILDX = docker buildx build --platform $(PLATFORM) --builder multiplatform-builder
#OUTPUT = --output type=image,name=$(REGISTRY),push=true,compression=zstd,compression-level=19,force-compression=true,oci-mediatypes=true
OUTPUT = --output type=image,name=$(REGISTRY),push=true,compression=gzip,compression-level=9,force-compression=true
OPTIONS = --provenance false
all:
	$(BUILDX) $(OUTPUT) $(OPTIONS) --pull -f build/Dockerfile .

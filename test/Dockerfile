FROM scratch AS mold
COPY data /src/deploy/

# Final image
FROM wyga/deploy-template:v3
COPY --from=mold /src /src/

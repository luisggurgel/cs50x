verification = ["gif", "jpg", "jpeg", "png", "pdf", "txt", "zip"]
solution = ["image/gif", "image/jpeg", "image/jpeg", "image/png", "application/pdf", "text/plain", "application/zip"]

file_name = input("File name: ").strip()
file_name = file_name.split(".")
extension = file_name[-1].lower()

if extension in verification:
    print(solution[verification.index(extension)])
else:
    print("application/octet-stream")

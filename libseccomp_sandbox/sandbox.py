import os.path

def exec_is_valid():
    sandboxOutputFilename = "sandbox_out.txt"
    unvalid_error = "Bad system call"

    os.system("./sandbox -n -v hfsplus 2> " + sandboxOutputFilename)

    with open(sandboxOutputFilename) as sandboxOutputFile:
        if unvalid_error in sandboxOutputFile.read():
            ret = False
        else:
            ret = True

    
    os.system("rm " + sandboxOutputFilename)
    os.system("rm sandbox.pyc")

    return ret






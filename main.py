import pathlib

DAG_DIRNAME = pathlib.Path(__file__).resolve().parents[1]

print(DAG_DIRNAME)
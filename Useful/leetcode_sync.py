import requests
import os
import re
import getpass

API_URL = "https://leetcode.com/api/problems/all/"
SCRIPT_DIR = os.path.dirname(os.path.abspath(__file__))
PROBLEMS_DIR = os.path.join(SCRIPT_DIR, "..", "Problems")

NAME_PATTERN = re.compile(r"^\s*(\d+)\.\s*(.+?)\s*$")


def normalize(title):
    return re.sub(r"[^a-z0-9]", "", title.lower())


def fetch_solved(session_cookie):
    session = requests.Session()
    session.cookies.set("LEETCODE_SESSION", session_cookie, domain="leetcode.com")
    session.headers.update({"User-Agent": "Mozilla/5.0"})

    resp = session.get(API_URL)
    resp.raise_for_status()
    data = resp.json()

    solved = {}
    for item in data["stat_status_pairs"]:
        if item.get("status") == "ac":
            stat = item["stat"]
            solved[int(stat["frontend_question_id"])] = stat["question__title"]
    return solved


def load_folders():
    folders = {}
    duplicates = {}
    for name in os.listdir(PROBLEMS_DIR):
        if not os.path.isdir(os.path.join(PROBLEMS_DIR, name)):
            continue
        m = NAME_PATTERN.match(name)
        if m:
            qid, title = int(m.group(1)), m.group(2)
            duplicates.setdefault(qid, []).append(name)
            folders[qid] = (title, name)
    dup_report = {qid: names for qid, names in duplicates.items() if len(names) > 1}
    return folders, dup_report


def main():
    if not os.path.isdir(PROBLEMS_DIR):
        print(f"Could not find folder: {os.path.abspath(PROBLEMS_DIR)}")
        print("Edit PROBLEMS_DIR at the top of the script to point at the right path.")
        return

    session_cookie = getpass.getpass("Paste your LEETCODE_SESSION cookie value: ").strip()
    solved = fetch_solved(session_cookie)

    with open("solved_problems.txt", "w", encoding="utf-8") as f:
        for qid, title in sorted(solved.items()):
            f.write(f"{qid}. {title}\n")

    folders, dup_report = load_folders()

    missing = []
    renamed = []
    orphans = []

    for qid, expected_title in sorted(solved.items()):
        if qid not in folders:
            missing.append((qid, expected_title))
        else:
            actual_title, folder_name = folders[qid]
            if normalize(actual_title) != normalize(expected_title):
                renamed.append((qid, expected_title, folder_name))

    for qid, (title, name) in folders.items():
        if qid not in solved:
            orphans.append((qid, name))

    with open("missing_problems.txt", "w", encoding="utf-8") as f:
        for qid, title in missing:
            f.write(f"{qid}. {title}\n")

    with open("renamed_problems.txt", "w", encoding="utf-8") as f:
        for qid, expected_title, folder_name in renamed:
            f.write(f"{qid}. expected \"{expected_title}\" but folder is \"{folder_name}\"\n")

    with open("duplicate_ids.txt", "w", encoding="utf-8") as f:
        for qid, names in sorted(dup_report.items()):
            f.write(f"{qid}: {names}\n")

    with open("orphan_folders.txt", "w", encoding="utf-8") as f:
        for qid, name in sorted(orphans):
            f.write(f"{qid}. folder \"{name}\" has no matching solved problem on LeetCode\n")

    print(f"Solved on LeetCode:      {len(solved)}")
    print(f"Unique folder ids found: {len(folders)}")
    print(f"Missing entirely:        {len(missing)}")
    print(f"Name mismatches:         {len(renamed)}")
    print(f"Duplicate folder ids:    {len(dup_report)}")
    print(f"Orphan folders:          {len(orphans)}")


if __name__ == "__main__":
    main()